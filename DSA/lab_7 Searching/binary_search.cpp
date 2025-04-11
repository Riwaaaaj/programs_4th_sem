#include<iostream>
using namespace std;
#define MAX_SIZE 7

int main() {
    int arr[] = {1, 2, 7, 8, 10, 16, 20}; // Sorted array
    int item;
    cout << "Enter the item you want to search: ";
    cin >> item;

    int low = 0, high = MAX_SIZE - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        if (arr[mid] == item) {
            cout << "Item found at index: " << mid << "\n";
            found = true;
            break;
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Item not found\n";
    }

    return 0;
}
/*
Enter the item you want to search: 2
Item found at index: 1

Enter the item you want to search: 78
Item not found
*/