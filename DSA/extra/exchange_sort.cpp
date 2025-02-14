#include <iostream>
using namespace std;

// Function to perform Exchange Sort
void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]); // Swap if elements are in the wrong order
            }
        }
    }
}

// Function to display the array
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

    exchangeSort(arr, n); // Perform Exchange Sort

    cout << "Sorted array using exchangeSort: ";
    display(arr, n);

    return 0;
}