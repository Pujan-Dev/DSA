#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello this is a test";
  char *token;
  token = strtok(str, " ");
  while (token != NULL) {
    printf("Token: %s\n", token);
    token = strtok(NULL, " ");
  }

  return 0;
}
