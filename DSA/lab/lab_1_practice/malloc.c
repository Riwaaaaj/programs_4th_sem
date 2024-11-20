#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, i, *ptr, sum = 0;

  printf("Enter the number of elements");
  scanf("%d", &size);

  ptr = (int *)malloc(size * sizeof(int));

  printf("Enter the elements of array: \n");
  for (i = 0; i < size; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  free(ptr);
  return 0;
}