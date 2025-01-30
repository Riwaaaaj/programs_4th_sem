#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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

  insertionSort(arr, n);

  cout << "Sorted array using insertionSort: ";
  display(arr, n);

  return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using insertionSort: 1 5 7 8 9 10 
*/