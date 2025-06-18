#include <stdio.h>
#include <stdlib.h>
struct SLL {
  int data;
  struct SLL *next;
};
struct SLL *first, *last = NULL;

void Display() {
  struct SLL *temp;
  if (first == NULL) {
    printf("The list is empty");
  } else {
    temp = first;
    while (temp != NULL) {
      printf("%d->", temp->data);
      temp = temp->next;
    }
    printf("Null\n");
  }
}

void insert_at_beginning(int element) {
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  NewNode->data = element;
  NewNode->next = NULL;
  if (first == NULL) {
    first = NewNode;
    last = NewNode;
    printf("%d was Inserted\n", first->data);

  } else {
    NewNode->next = first;
    first = NewNode;
    printf("%d was Inserted\n", first->data);
  }
}

void insert_at_end(int element) {
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  NewNode->data = element;
  NewNode->next = NULL;
  if (first == NULL) {
    first = NewNode;
    last = NewNode;
    printf("%d was Inserted\n", first->data);

  } else {
    last->next = NewNode;
    last = NewNode;
    printf("%d was Inserted\n", first->data);
  }
}

void insert_at_specific_position(int element, int POS) {
  struct SLL *NewNode, *temp;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  NewNode->data = element;
  NewNode->next = NULL;
  if (POS <= 0)
    printf("Invalid Position");
  else if (POS == 1 || first == NULL)
    insert_at_beginning(element);
  else {
    temp = first;
    for (int i = 1; (i < POS - 1) && (temp->next != NULL); i++) {
      temp = temp->next;
    }
    if (temp == last) {

      insert_at_end(element);

    } else {
      NewNode->next = temp->next;
      temp->next = NewNode;
      printf("%d was inserted\n", NewNode->data);
    }
  }
}

void deletion_from_the_beginning() {
  struct SLL *temp;
  if (first == NULL)
    printf("List is Empty");
  else if (first->next == NULL) {
    temp = first;
    temp = first = NULL;
    printf("%d will be removed\n", temp->data);
    free(temp);
  } else {
    temp = first;
    first = first->next;

    printf("%d will be removed\n", temp->data);
    free(temp);
  }
}

void deletion_from_the_end() {
  struct SLL *temp;
  if (first == NULL)
    printf("List is Empty");
  else if (first->next == NULL) {
    temp = first;
    temp = first = NULL;
    printf("%d will be removed\n", temp->data);
    free(temp);

  } else {
    temp = first;
    while (temp->next != last) {
      temp = temp->next;
    }
    last = temp;
    temp = temp->next;

    printf("%d will be  removed \n", temp->data);
    free(temp);
    last->next = NULL;
  }
}

void deletion_from_the_specific_pos(int POS) {
  struct SLL *temp, *tempp;
  if (POS <= 0 || first == NULL)
    printf("Invalid Deletion");
  else if (POS == 1)
    deletion_from_the_beginning();
  else {
    temp = first;
    for (int i = 1; (i < (POS - 1)) && (temp->next != last); i++) {
      temp = temp->next;
    }
    if (temp->next == last) {
      deletion_from_the_end();
    } else {
      tempp = temp->next;
      temp->next = tempp->next;
      printf("%d element deleted from the %d position\n", tempp->data, POS);
      free(tempp);
    }
  }
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
