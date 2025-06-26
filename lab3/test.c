
#include <stdio.h>
#include <time.h>

void sort(int array[], int n); // Sorting function prototype

int main() {
  int array[] = {/* Some large number of elements */};
  int n = sizeof(array) / sizeof(array[0]);

  // Record start time
  clock_t start = clock();

  // Perform sorting
  sort(array, n);

  // Record end time
  clock_t end = clock();

  // Calculate time taken
  double time_taken =
      ((double)(end - start)) / CLOCKS_PER_SEC; // Convert to seconds

  printf("Sorting took %f seconds to execute \n", time_taken);
  return 0;
}

void sort(int array[], int n) {
  // Sorting logic (e.g., quicksort, bubblesort)
}
