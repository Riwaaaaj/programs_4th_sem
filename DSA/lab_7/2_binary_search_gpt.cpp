#include <iostream>
using namespace std;
#define MAX_SIZE 7

int binarySearch(int arr[], int low, int high, int item) {
    if (low > high) {
        return -1; // Item not found
    }

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    if (arr[mid] == item) {
        return mid; // Item found, return index
    }

    if (item < arr[mid]) {
        return binarySearch(arr, low, mid - 1, item);
    }

    return binarySearch(arr, mid + 1, high, item);
}

int main() {
    int arr[] = {1, 2, 7, 8, 10, 16, 20}; // sorted array
    int item;

    cout << "Enter your item that you want to search: ";
    cin >> item;

    int index = binarySearch(arr, 0, MAX_SIZE - 1, item);

    if (index != -1) {
        cout << "Item " << item << " found at index " << index << ".\n";
    } else {
        cout << "Item " << item << " not found in the array.\n";
    }

    return 0;
}