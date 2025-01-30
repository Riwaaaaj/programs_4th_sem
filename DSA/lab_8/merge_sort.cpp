#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArray[n1];
  int rightArray[n2];

  for(int i = 0; i < n1; i++) 
    leftArray[i] = arr[left + i];
  for(int i = 0; i < n2; i++) 
    rightArray[i] = arr[mid + i + 1];

  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2) {
    if(leftArray[i] < rightArray[j]) {
      arr[k] = leftArray[i];
      i++;
    } else {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  while(i < n1) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }
  while(j < n2) {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array using Merge Sort: ";
    display(arr, n);

    return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array using Merge Sort: 1 5 7 8 9 10 
*/