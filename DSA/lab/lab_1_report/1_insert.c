#include <stdio.h>
#include <stdlib.h>

void insert(int *, int);
// void delete();
// void update();
void traverse(int *, int);
// void merge();

int main() {
  int *ptr, size;

  printf("Enter the number of elements: \n");
  scanf("%d", &size);

  insert(ptr, size);
  traverse(ptr, size);

  free(ptr);
  return 0;
}

void insert(int *ptr, int size) {

  ptr = (int *)malloc(size * sizeof(int));

  printf("Enter the elements of array: \n");
  for (int i = 0; i < size; ++i) {
    scanf("%d", ptr + i);
  }
}

void traverse(int *ptr, int size) {
  printf("The elements of array: \n");
  for (int i = 0; i < size; ++i) {
    printf("%d ", *(ptr + i));
  }
}
