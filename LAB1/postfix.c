#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct STACK {
  int TOS;
  float data[MAX];
};

void push(struct STACK *S, float element) {
  if (S->TOS >= MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  S->data[++(S->TOS)] = element;
}

float POP(struct STACK *S) {
  if (S->TOS < 0) {
    printf("Stack Underflow\n");
    return -1;
  }
  return S->data[(S->TOS)--];
}

int isEmpty(struct STACK *S) { return (S->TOS == -1); }

int isFull(struct STACK *S) { return (S->TOS == MAX - 1); }

int main() {
  char exp[MAX];
  float op1, op2, result;
  struct STACK S = {-1};
  printf("Enter your expression:");
  fgets(exp, MAX, stdin);
  char *token = strtok(exp, " ");
  int i = 0;
  while (token != NULL) {
    printf("Scanning %s\n", token);
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      push(&S, atof(token));
      printf("pushed");
    } else {
      printf("popped");

      op2 = POP(&S);
      op1 = POP(&S);
      printf("Popped");
      switch (token[0]) {
      case '+':
        result = op1 + op2;
        break;
      case '-':
        result = op1 - op2;
        break;
      case '*':
        result = op1 * op2;
        break;
      case '/':
        result = op1 / op2;
        break;
      default:
        printf("Invalid operator");
        return 1;
      }
      push(&S, result);
    }
    token = strtok(NULL, " ");
  }
  printf("Result = %.2f\n", POP(&S));
  return 0;
}
