#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr, i, n1, n2;
  printf("Enter size of array: ");
  scanf("%d", &n1);
  ptr = (int *)malloc(n1 * sizeof(int));

  printf("Address of previously allocated memory: ");
  for (i = 0; i < n1; ++i)
    printf("%p\t", (ptr + i)); // Corrected to %p

  printf("\nEnter new size of array: ");
  scanf("%d", &n2);
  ptr = realloc(ptr, n2 * sizeof(int)); // Ensure correct size in bytes

  printf("Address of newly allocated memory: ");
  for (i = 0; i < n2; ++i)
    printf("%p\t", (ptr + i)); // Corrected to %p

  free(ptr); // Free allocated memory
  return 0;
}
