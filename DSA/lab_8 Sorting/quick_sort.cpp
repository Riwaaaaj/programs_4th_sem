#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  i++;
  swap(arr[i], arr[high]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array using Quick Sort: ";
    display(arr, n);

    return 0;
}
