#include <stdio.h>
#include <time.h> // Required for clock() and CLOCKS_PER_SEC

int main() {
  clock_t start_time, end_time;
  double cpu_time_used;

  // Record the starting time
  start_time = clock();

  // --- Your program's code goes here ---
  // For demonstration, let's include a loop that performs some calculations
  long long sum = 0;
  for (long long i = 0; i < 1000000000; i++) {
    sum += i;
  }
  printf("Sum calculated: %lld\n", sum);
  // --- End of your program's code ---

  // Record the ending time
  end_time = clock();

  // Calculate the CPU time used
  cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  printf("Execution time: %f seconds\n", cpu_time_used);

  return 0;
}
