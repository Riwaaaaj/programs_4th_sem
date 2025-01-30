#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for(int j = i + 1; j < n; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
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

  selectionSort(arr, n);

  cout << "Sorted array using selectionSort: ";
  display(arr, n);

  return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using selectionSort: 1 5 7 8 9 10 
*/