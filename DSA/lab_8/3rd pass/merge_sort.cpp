#include <iostream>
#define MAX_SIZE 4
using namespace std;

int merge(int arr[], int low, int mid, int high) {
  
}

void mergeSort(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
  }

void display(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << "\n";
  }
}

int main() {
  int n = MAX_SIZE;
  int a[] = {9, 4, 3, 2};

  mergeSort(a, 0, n - 1);
  display(a, n);
  return 0;
}