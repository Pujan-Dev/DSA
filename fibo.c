#include <math.h>
#include <stdio.h>

int Fibonacci(int n) {
  const double phi = (1 + sqrt(5)) / 2;
  const double psi = (1 - sqrt(5)) / 2;

  // Use Binet's formula
  double fib_n = (pow(phi, n) - pow(psi, n)) / sqrt(5);

  // Round the result to nearest integer
  return (int)(fib_n + 0.5);
}

int main() {
  int n = 40;
  printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));
  return 0;
}
