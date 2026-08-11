#include "evaluator.h"
#include <stdio.h>

int variables[26];

int evaluate(tnode *t) {
    if (t == NULL)
        return 0;

    switch (t->nodetype) {
        case NODE_NUM:
            return t->val;

        case NODE_ID:
            return variables[t->varname[0] - 'a'];

        case NODE_PLUS:
            return evaluate(t->left) + evaluate(t->right);

        case NODE_MINUS:
            return evaluate(t->left) - evaluate(t->right);

        case NODE_MUL:
            return evaluate(t->left) * evaluate(t->right);

        case NODE_DIV:
            return evaluate(t->left) / evaluate(t->right);

        case NODE_ASSIGN:
            variables[t->left->varname[0] - 'a'] = evaluate(t->right);
            return 0;

        case NODE_READ:
            scanf("%d", &variables[t->left->varname[0] - 'a']);
            return 0;

        case NODE_WRITE:
            printf("%d\n", evaluate(t->left));
            return 0;

        case NODE_CONNECTOR:
            evaluate(t->left);
            evaluate(t->right);
            return 0;
    }

    return 0;
}