#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  for(int i = 0; i < n - 1; i++) {
    bool flag = 1;
    for(int j = 0; j < n - 1 - i; j++) {
      if(arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        flag = true;
      }
      if(!flag)
        break;
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

  bubbleSort(arr, n);

  cout << "Sorted array using bubbleSort: ";
  display(arr, n);

  return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using bubbleSort: 1 5 7 8 9 10
*/