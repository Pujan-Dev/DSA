#include <stdio.h>
#define MAX 20

struct STACK {
    int TOS;
    char data[MAX];
};

void push(struct STACK *s, char ch) {
    if (s->TOS < MAX - 1)
        s->data[++(s->TOS)] = ch;
}

char pop(struct STACK *s) {
    if (s->TOS >= 0)
        return s->data[(s->TOS)--];
    return '\0';
}

int priority(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        default: return -1;
    }
}

int main() {
    struct STACK temp = {-1};
    struct STACK output = {-1};
    char infix[MAX];
    char gbg, operator;
    int i = 0;

    printf("Enter Infix Expression: ");
    fgets(infix, MAX, stdin);

    while (infix[i] != '\n' && infix[i] != '\0') {
        switch (infix[i]) {
            case '(':
                push(&temp, '(');
                break;

            case ')':
                while (temp.TOS != -1 && temp.data[temp.TOS] != '(') {
                    gbg = pop(&temp);
                    push(&output, gbg);
                }
                pop(&temp); // Pop '('
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                operator = infix[i];
                while (temp.TOS != -1 && priority(temp.data[temp.TOS]) >= priority(operator)) {
                    gbg = pop(&temp);
                    push(&output, gbg);
                }
                push(&temp, operator);
                break;

            default:
                push(&output, infix[i]);
                break;
        }
        i++;
    }

    while (temp.TOS != -1) {
        gbg = pop(&temp);
        push(&output, gbg);
    }

    printf("The POSTFIX expression is: %s\n", output.data);
    return 0;
}

