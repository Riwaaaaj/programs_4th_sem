#include<iostream>
using namespace std;
#define MAX_SIZE 6

int main() {
  int arr[] = {2, 10, 16, 7, 8, 1};
  int item;
  cout << "Enter your item that you want to search: ";
  cin >> item; 
  int last = arr[MAX_SIZE - 1]; 
  arr[MAX_SIZE - 1] = item; 
  int i = 0;
  while(arr[i] != item) {
   i++;
  }

  arr[MAX_SIZE - 1] = last; 

  if(i <  MAX_SIZE - 1 || item == last) { 
    cout << "Item found at index " << i << "\n";
  } else {
    cout << "Item not found" << "\n";
  }
  return 0;
}