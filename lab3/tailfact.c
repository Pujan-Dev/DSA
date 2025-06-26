#include <stdio.h>
#include <time.h>
#define MAX 100
long int table[MAX];

int tailFact(int n, int a) {
  if (n == 1) {
    return a;
  } else {
    return tailFact(n - 1, n * a);
  }
}

int Sum(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n + Sum(n - 1);
  }
}
long int FiboM(long int n) {
  if (n == 1 || n == 2)
    return 1;
  else {
    table[n] = -1;
    if (table[n] == -1) {
      table[n] = FiboM(n - 1) + FiboM(n - 2);
    }
    return table[n];
  }
}

int GCD(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GCD(b, a % b);
  }
}
int moves = 0;
void TOH(int n, char src, char dst, char temp) {
  moves++;
  if (n == 1) {
    printf("Move disk %d from %c to %c\n", n, src, dst);
  } else {
    TOH(n - 1, src, temp, dst);
    printf("Move disk %d from %c to %c\n", n, src, dst);

    TOH(n - 1, temp, dst, src);
  }
}
int main() {
  // long int fibo = FiboM(45);
  // printf("fibo using table: %ld\n", fibo);
  // printf("\n tailFact for n=10 == %d", tailFact(10, 1));
  //
  // printf("\n sum for n=10 == %d", Sum(10));
  // printf("\n GCD for n1=10 and n2= 20 == %d", GCD(10, 20));
  // clock_t start, end;

  double cpu_time_used;
  clock_t start_time, end_time;
  printf("\n tailFact for n=3\n");

  start_time = clock();
  TOH(20, 'A', 'C', 'B');

  end_time = clock();

  cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  printf("Execution time: %f seconds\n", cpu_time_used);
  printf("%d", moves);

  return 0;
}
