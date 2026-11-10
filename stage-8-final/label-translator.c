#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * The compiler first emits symbolic labels. This tool scans that file twice:
 * first to map labels to instruction addresses, then to remove label lines and
 * replace symbolic jump/call/table entries with numeric addresses.
 */
#define START_ADDRESS 2056
#define HEADER_LINES 8

/* A linked list stores as many labels as the source file contains. */
typedef struct Label {
    char name[20];
    int address;
    struct Label *next;
} Label;

Label* head = NULL;

/* Store one label/address pair during the translator's first pass. */
void addLabel(char* name, int address) {
    Label *temp = (Label *)malloc(sizeof(Label));
    strcpy(temp->name, name);
    temp->address = address;
    temp->next = head;
    head = temp;
}

/* Look up a label recorded by firstPass; stop with an error if it is missing. */
int findLabelAddress(char* name) {
    Label* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp->address;
        }

        temp = temp->next;
    }

    printf("Error: label %s not found\n", name);
    exit(1);
}

/* Recognize F<number> names, which may appear as function addresses in MOVs. */
static int isFunctionLabel(const char *name) {
    const char *digit;

    if (name == NULL || name[0] != 'F' || name[1] == '\0') return 0;
    for (digit = name + 1; *digit != '\0'; ++digit) {
        if (!isdigit((unsigned char)*digit)) return 0;
    }
    return 1;
}

/* Keep register operands such as R0 from being mistaken for labels. */
static int isRegisterOperand(const char *name) {
    const char *digit;

    if (name == NULL || name[0] != 'R' || name[1] == '\0') return 0;
    for (digit = name + 1; *digit != '\0'; ++digit) {
        if (!isdigit((unsigned char)*digit)) return 0;
    }
    return 1;
}

/* Detect a label-only line and copy its name into the output parameter. */
int isLabel(char* line, char* label) {
    char* colon = strchr(line, ':'); // strchr finds the first pos a letter comes in a word

    if (colon == NULL)
        return 0;
    
    char *p = colon + 1;
    while (*p != '\0') {
        if (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\r')
            return 0;

        p++;
    }

    // Make sure the colon occurs immediately after the label name, with no spaces
    int length = colon - line;

    // if no chars before colon, no label name
    // since char label is of size 20, we cant write past
    if (length <= 0 || length >= 20) return 0;

    strncpy(label, line, length);
    label[length] = '\0';
    return 1;
}

/* First pass: calculate instruction addresses and record each label location. */
void firstPass(FILE* file) {
    char line[200];
    char label[20];

    int address = START_ADDRESS;
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        lineNumber++;

        /* The XSM header is metadata and does not consume instruction addresses. */
        if (lineNumber <= HEADER_LINES)
            continue;

        if (isLabel(line, label)) {
            addLabel(label, address);
            continue; /* A label names the next instruction; it is not an instruction. */
        }

        // Every XSM instruction occupies 2 words.
        address += 2;
    }
}

/* Second pass: discard label-only lines and replace symbolic targets with addresses. */
void secondPass(FILE* input, FILE* output) {
    char line[200];
    int lineNumber = 0;
    
    /* Revisit the source from the start after firstPass built the label map. */
    while (fgets(line, sizeof(line), input) != NULL) {
        lineNumber++;

        /* Copy the XSM header unchanged. */
        if (lineNumber <= HEADER_LINES) {
            fprintf(output, "%s", line);
            continue;
        }

        char label[20];

        /* Label-only lines become addresses and do not appear in final output. */
        if (isLabel(line, label)) continue;

        // Translate symbolic unconditional-jump and function-call labels.
        char instruction[20];
        char operand[20];
        if (sscanf(line, "%19s %19s", instruction, operand) == 2) {
            operand[strcspn(operand, "\r\n")] = '\0';

            if ((strcmp(instruction, "JMP") == 0 || strcmp(instruction, "CALL") == 0) &&
                isalpha((unsigned char)operand[0]) && !isRegisterOperand(operand)) {
                fprintf(output, "%s %d\n", instruction, findLabelAddress(operand));
                continue;
            }
        }

        /* Translate method labels loaded as values for virtual tables. */
        char destination[20];
        char source[20];
        if (sscanf(line, "%19s %19[^,], %19s", instruction,
                   destination, source) == 3) {
            source[strcspn(source, "\r\n")] = '\0';
            if (strcmp(instruction, "MOV") == 0 && isFunctionLabel(source)) {
                fprintf(output, "%s %s, %d\n", instruction, destination,
                        findLabelAddress(source));
                continue;
            }
        }

        /* Conditional jumps have a register operand and a label operand. */
        char registerName[20];
        char jumpLabel[20];
        if (sscanf(line, "%19s %19[^,], %19s", instruction, registerName, jumpLabel) == 3) {
            jumpLabel[strcspn(jumpLabel, "\r\n")] = '\0';

            if (strcmp(instruction, "JZ") == 0 || strcmp(instruction, "JNZ") == 0) {
                fprintf(output, "%s %s, %d\n", instruction, registerName, findLabelAddress(jumpLabel));
                continue;
            }
        }

        /* Instructions without symbolic labels pass through unchanged. */
        fprintf(output, "%s", line);
    }
}


/*
 * FUNCTION: main
 * PURPOSE: Run both label-translation passes on the named XSM files.
 * INPUT: Source target file and destination executable file from argv.
 * RETURN: 0 on success, nonzero if arguments or files are invalid.
 * FLOW: Open files, collect labels/addresses, rewind the source, then write
 * translated instructions to the destination.
 */
int main(int argc, char *argv[]) {
    FILE *input;
    FILE *output;

    if (argc != 3) {
        printf("Usage: %s <input.xsm> <output.xsm>\n", argv[0]);

        return 1;
    }

    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return 1;
    }

    /* Pass 1 records all symbolic labels and their instruction addresses. */
    firstPass(input);
    rewind(input);

    output = fopen(argv[2], "w");

    if (output == NULL) {
        printf("Cannot create %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    /* Pass 2 removes labels and writes the address-based target file. */
    secondPass(input, output);

    fclose(input);
    fclose(output);
    return 0;
}
