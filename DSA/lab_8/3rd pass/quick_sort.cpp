#include <iostream>
#define MAX_SIZE 4
using namespace std;

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int  i = low - 1; 

  for(int j = low; j < high; j++) {
    if(arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[++i], arr[high]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  if( low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

void display(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << "\n";
  }
}

int main() {
  int n = MAX_SIZE;
  int a[] = {9, 4, 3, 2};

  quickSort(a, 0, n - 1);
  display(a, n);
  return 0;
}