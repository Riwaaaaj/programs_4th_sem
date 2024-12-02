#include <iostream>
using namespace std;

void insert(int *&ptr, int size) {
  ptr = new int[size];
  if (ptr == nullptr) {
    cout << "Memory allocation failed!" << endl;
    exit(1);
  }
  cout << "Enter the elements of array: " << endl;
  for (int i = 0; i < size; ++i) {
    cin >> ptr[i];
  }
}

bool indexCheck(int i, int size) {
  if (i >= size || i < 0) {
    cout << "The given index doesn't exist." << endl;
    return true;
  }
  return false;
}

void deleteElement(int *&ptr, int &size) {
  int i;
  cout << "Enter the index that you want to delete: " << endl;
  cin >> i;
  if (indexCheck(i, size))
    return;

  for (int j = i; j < size - 1; ++j) {
    ptr[j] = ptr[j + 1];
  }

  int *temp = new int[size - 1];
  if (temp == nullptr && size > 1) {
    cout << "Memory reallocation failed!" << endl;
    return;
  }

  for (int j = 0; j < size - 1; ++j) {
    temp[j] = ptr[j];
  }

  delete[] ptr;
  ptr = temp;
  size--;
}

void update(int *ptr, int size) {
  int i;
  cout << "Enter the index that you want to update: " << endl;
  cin >> i;
  if (indexCheck(i, size))
    return;

  cout << "Enter the new value: " << endl;
  cin >> ptr[i];
}

void traverse(int *ptr, int size) {
  cout << "The elements of the array: " << endl;
  for (int i = 0; i < size; ++i) {
    cout << ptr[i] << " ";
  }
  cout << endl;
}

void pop(int &top) {
  if (top == -1) {
    cout << "Stack underflow!!" << endl;
    exit(0);
  }
  top--;
}

int main() {
  int *ptr = nullptr;
  int size, top = -1;

  cout << "Enter the number of elements: " << endl;
  cin >> size;

  insert(ptr, size);
  deleteElement(ptr, size);
  update(ptr, size);
  traverse(ptr, size);

  delete[] ptr;
  return 0;
}
