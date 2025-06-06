#include <stdio.h>
#define true 1
#define false 0
#define MAX 5

struct STACK {
  int TOS;
  int data[MAX];
};

int isFull(struct STACK *s) { 
  return s->TOS == MAX - 1 ? true : false; }

int isEmpty(struct STACK *s) { 
  return s->TOS == -1 ? true : false; 
}
void push(struct STACK *s, int element) { s->data[++(s->TOS)] = element; }
int pop(struct STACK *s) { return s->data[s->TOS--]; }

int peek(struct STACK *s) { return s->data[s->TOS]; }

int main() {
  int choice, value;
  struct STACK S = {-1}; // init the tos to -1
  do {
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
    printf(">");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      if (isFull(&S))
        printf("STACK OVERFLOW\n");
      else {
        printf("Enter an Element");
        scanf("%d", &value);
        push(&S, value);
        printf("%d was PUSHED into the stack.", value);
      }
      break;
    case 2:
      if (isEmpty(&S))
        printf("Stack Underflow");
      else {
        printf("%d was popped\n", pop(&S));
      }
      break;
    case 3:
      if (isEmpty(&S))
        printf("Stack Underflow");
      else {
        printf("%d is at the top\n", peek(&S));
      }
      break;
    case 4:
      printf("Program ended");
      break;
    default:
      printf("invalid invalid input");
      break;
    }
  } while (choice != 4);
  printf("\n");
}
