#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
  for (int gap = n / 2; 0 < gap; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int key = arr[i];
      int j = i;
      while (gap <= j && key < arr[j - gap]) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = key;
    }
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  display(arr, n);

  shellSort(arr, n);

  cout << "Sorted array using Shell Sort: ";
  display(arr, n);

  return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using Shell Sort: 1 5 7 8 9 10 
*/
