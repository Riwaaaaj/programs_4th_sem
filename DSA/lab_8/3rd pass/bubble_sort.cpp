#include <iostream>
#define MAX_SIZE 4
using namespace std;

void bubbleSort(int a[], int n) {
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = temp;
      }
    }
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

  bubbleSort(a, n);
  display(a, n);
  
  return 0;
}