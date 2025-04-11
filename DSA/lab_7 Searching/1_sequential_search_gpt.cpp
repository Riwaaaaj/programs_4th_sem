#include <iostream>
using namespace std;
#define M 6

void linearSearch(int arr[], int item) {
    int last = arr[M - 1];  // Store the last element
    arr[M - 1] = item;      // Place the item at the last position (sentinel)

    int i = 0;
    while (arr[i] != item) {
        i++;
    }

    arr[M - 1] = last;  // Restore the original last element

    // Check if the found index is within the original array bounds
    if (i < M - 1 || last == item) {
      cout << "Item found at index " << i << "\n";
    } else {
      cout << "Item not found\n";
    }
}

int main() {
    int arr[] = {2, 10, 16, 7, 8, 1};
    int item;
    cout << "Enter your item that you want to search: ";
    cin >> item;

    linearSearch(arr, item);
    return 0;
}
