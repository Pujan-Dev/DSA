#include <stdio.h>
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
    return -1; // indicate error
  }
  return S->data[(S->TOS)--];
}

int isEmpty(struct STACK *S) { return (S->TOS == -1); }

int isFull(struct STACK *S) { return (S->TOS == MAX - 1); }

int main() {
  struct STACK S;
  S.TOS = -1;

  int choice;
  float element;

  do {
    printf("\nEnter your choice");
    printf("\n1. Push\n2. POP\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter an element: ");
      scanf("%f", &element);
      push(&S, element);
      break;
    case 2:
      if (!isEmpty(&S)) {
        float popped = POP(&S);
        printf("Popped value: %f\n", popped);
      } else {
        printf("The stack is empty\n");
      }
      break;
    case 3:
      printf("EXITING...\n");
      break;
    default:
      printf("Invalid input\n");
    }
  } while (choice != 3);

  return 0;
}
