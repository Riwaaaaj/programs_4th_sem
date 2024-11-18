#include <stdio.h>
int main() {
  int n1, n2;

  printf("Enter the total number of elements in the first array: \n");
  scanf("%d", &n1);
  printf("Enter the total number of elements in the second array: \n");
  scanf("%d", &n2);

  int arr1[n1], arr2[n2];
  printf("Enter the elements of the first array: \n");
  for (int i = 0; i < n1; ++i) {
    scanf("%d", &arr1[i]);
  }
  printf("Enter the elements of the second array: \n");
  for (int j = 0; j < n2; ++j) {
    scanf("%d", &arr2[j]);
  }

  int merged[n1 + n2];
  for (int i = 0; i < n1; ++i) {
    merged[i] = arr1[i];
  }
  for (int j = 0; j < n2; ++j) {
    merged[n1 + j] = arr2[j];
  }

  printf("Merged array: ");
  for (int k = 0; k < n2 + n1; ++k) {
    printf("%d ", merged[k]);
  }
  printf("\n");

  return 0;
}