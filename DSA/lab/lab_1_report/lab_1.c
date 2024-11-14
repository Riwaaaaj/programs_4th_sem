#include <stdio.h>
#include <stdlib.h>

int indexCheck(int, int);
void insert(int **, int);
void delete(int **, int *);
void update(int *, int);
void traverse(int *, int);

int main() {
  int *ptr = NULL, size;

  printf("Enter the number of elements: \n");
  scanf("%d", &size);

  insert(&ptr, size);
  delete (&ptr, &size);
  update(ptr, size);
  traverse(ptr, size);
  free(ptr);
  return 0;
}

void insert(int **ptr, int size) {

  *ptr = (int *)malloc(size * sizeof(int));

  if (*ptr == NULL) {
    printf("Memory allocation failed!");
    exit(1);
  }

  printf("Enter the elements of array: \n");
  for (int i = 0; i < size; ++i) {
    scanf("%d", (*ptr) + i);
  }
}

void delete(int **ptr, int *size) {
  int i;
  printf("Enter the index that you want to delete: \n");
  scanf("%d", &i);

  if (indexCheck(i, *size))
    return;
  while (i < *size - 1) {
    (*ptr)[i] = (*ptr)[i + 1];
    i++;
  }

  int *temp = realloc(*ptr, (*size - 1) * sizeof(int));

  if (temp == NULL && *size > 1) {
    printf("Memory reallocation failed!\n");
    return;
  }

  *ptr = temp;
  (*size)--;
}

void update(int *ptr, int size) {
  int i;
  printf("Enter the index that you want to update: \n");
  scanf("%d", &i);

  if (indexCheck(i, size))
    return;

  printf("Enter the new value: \n");
  scanf("%d", (ptr + i));
}

void traverse(int *ptr, int size) {
  printf("The elements of array: \n");
  for (int i = 0; i < size; ++i) {
    printf("%d ", *(ptr + i));
  }
}

int indexCheck(int i, int size) {
  if (i >= size || i < 0) {
    printf("The given index doesn't exist.\n");
    return 1;
  }
  return 0;
}