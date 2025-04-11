#include <stdio.h>
#include <stdlib.h>

int main() {
  int n1, n2, i, *ptr;
  printf("Enter number of elements: ");
  scanf("%d", &n1);
  ptr = (int *)calloc(n1, sizeof(int));
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(1);
  }

  for (i = 0; i < n1; ++i) {
    printf("%p ", ptr + i);
  }

  printf("\nEnter new number of elements: ");
  scanf("%d", &n2);

  ptr = realloc(ptr, n2);

  for (i = 0; i < n2; ++i) {
    printf("%p ", ptr + i);
  }
  printf("\n");
  free(ptr);
  return 0;
}
