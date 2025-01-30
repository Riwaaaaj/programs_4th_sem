#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];

    // Fill left and right temporary arrays
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    // Merge the arrays
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from a[]
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from b[]
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void printdata(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergesort(int arr[], int l, int r) {
    if (l >= r) {
        return; // Base condition to terminate recursion
    }

    int mid = (l + r) / 2;

    // Recursive calls for left and right halves
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);

    // Merge the sorted halves
    merge(arr, l, mid, r);
}

int main() {
    int arr[] = {3, 7, 5, 4, 9, 6, 8};
    int n = 7;

    cout << "Original array: ";
    printdata(arr, n);

    mergesort(arr, 0, n - 1);

    cout << "The sorted array is: ";
    printdata(arr, n);

    return 0;
}
