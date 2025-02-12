#include <iostream>
#include <cstring>
using namespace std;

void countingSort(int arr[], int n) {
  int maxVal = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  int count[maxVal + 1];
  memset(count, 0, sizeof(count));

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  int index = 0;
  for (int i = 0; i <= maxVal; i++) {
    while (count[i] > 0) {
      arr[index] = i;
      index++;
      count[i]--;
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

  countingSort(arr, n);

  cout << "Sorted array using Counting Sort: ";
  display(arr, n);

  return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using Counting Sort: 1 5 7 8 9 10 
*/
