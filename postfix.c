#include <stdio.h>
#include <math.h>
#include <ctype.h> 

#define MAX 100

struct STACK {
    int TOS;
    float data[MAX];
};

void push(struct STACK *s, float element) {
    if (s->TOS < MAX - 1) {
        s->data[++(s->TOS)] = element;
    } else {
        printf("Stack Overflow\n");
    }
}

float pop(struct STACK *s) {
    if (s->TOS >= 0) {
        return s->data[(s->TOS)--];
    } else {
        printf("Stack Underflow\n");
        return 0;
    }
}

int convert_to_digit(char ch) {
    return ch - '0'; 
}

int main() {
    struct STACK S;
    S.TOS = -1;
    char input[MAX];
    float result = 0;

    printf("Enter the postfix expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (isdigit(ch)) {
            push(&S, convert_to_digit(ch));
        } else {
            float op1 = pop(&S);
            float op2 = pop(&S);

            switch (ch) {
                case '*':
                    result = op2 * op1;
                    break;
                case '/':
                    result = op2 / op1;
                    break;
                case '-':
                    result = op2 - op1;
                    break;
                case '+':
                    result = op2 + op1;
                    break;
                case '^':
                    result = pow(op2, op1);
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }
            push(&S, result);
        }
    }

    result = pop(&S);
    printf("Result = %.2f\n", result);
    return 0;
}

