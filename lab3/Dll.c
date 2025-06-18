
#include <stdio.h>
#include <stdlib.h>

struct DLL {
  int data;
  struct DLL *prev;
  struct DLL *next;
};

struct DLL *first = NULL;
struct DLL *last = NULL;

void Display() {
  struct DLL *temp = first;
  if (first == NULL) {
    printf("The list is empty\n");
  } else {
    while (temp != NULL) {
      printf("%d <-> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

void insert_at_beginning(int element) {
  struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
  NewNode->data = element;
  NewNode->prev = NULL;
  NewNode->next = first;

  if (first == NULL) {
    last = NewNode;
  } else {
    first->prev = NewNode;
  }
  first = NewNode;
  printf("%d was Inserted at beginning\n", element);
}

void insert_at_end(int element) {
  struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
  NewNode->data = element;
  NewNode->next = NULL;
  NewNode->prev = last;

  if (last == NULL) {
    first = NewNode;
  } else {
    last->next = NewNode;
  }
  last = NewNode;
  printf("%d was Inserted at end\n", element);
}

void insert_at_specific_position(int element, int POS) {
  if (POS <= 0) {
    printf("Invalid Position\n");
    return;
  }
  if (POS == 1 || first == NULL) {
    insert_at_beginning(element);
    return;
  }

  struct DLL *temp = first;
  int i;
  for (i = 1; i < POS - 1 && temp->next != NULL; i++) {
    temp = temp->next;
  }

  if (temp->next == NULL) {
    insert_at_end(element);
  } else {
    struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    NewNode->data = element;

    NewNode->next = temp->next;
    NewNode->prev = temp;

    temp->next->prev = NewNode;
    temp->next = NewNode;
    printf("%d was Inserted at position %d\n", element, POS);
  }
}

void deletion_from_the_beginning() {
  if (first == NULL) {
    printf("List is Empty\n");
    return;
  }
  struct DLL *temp = first;
  printf("%d will be removed from beginning\n", temp->data);
  first = first->next;

  if (first != NULL)
    first->prev = NULL;
  else
    last = NULL;

  free(temp);
}

void deletion_from_the_end() {
  if (last == NULL) {
    printf("List is Empty\n");
    return;
  }
  struct DLL *temp = last;
  printf("%d will be removed from end\n", temp->data);
  last = last->prev;

  if (last != NULL)
    last->next = NULL;
  else
    first = NULL;

  free(temp);
}

void deletion_from_the_specific_pos(int POS) {
  if (POS <= 0 || first == NULL) {
    printf("Invalid Deletion\n");
    return;
  }
  if (POS == 1) {
    deletion_from_the_beginning();
    return;
  }

  struct DLL *temp = first;
  int i;
  for (i = 1; i < POS && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position %d not found\n", POS);
    return;
  }

  printf("%d element deleted from position %d\n", temp->data, POS);

  if (temp->prev != NULL)
    temp->prev->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = temp->prev;

  if (temp == last)
    last = temp->prev;

  free(temp);
}

int main() {
  insert_at_end(2);
  Display();
  insert_at_end(3);
  Display();
  insert_at_end(4);
  Display();
  insert_at_end(5);
  Display();

  insert_at_specific_position(400, 1);
  Display();
  insert_at_specific_position(300, 4);
  Display();
  insert_at_specific_position(600, 7);
  Display();

  deletion_from_the_beginning();
  Display();
  deletion_from_the_beginning();
  Display();
  deletion_from_the_end();
  Display();
  deletion_from_the_end();
  Display();
  deletion_from_the_specific_pos(2);
  Display();

  return 0;
}
