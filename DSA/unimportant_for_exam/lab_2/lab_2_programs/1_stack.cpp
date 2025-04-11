#include <cstdlib> // For exit function
#include <iostream>
#define MAX_SIZE 3
using namespace std;

class Stack {
  int arr[MAX_SIZE];
  int top;

public:
  Stack() : top(-1) {}
  void push(int item) {
    if (top == MAX_SIZE - 1) {
      cout << "Stack overflow" << endl;
      return;
    }
    arr[++top] = item;
  }

  int pop() {
    if(top == -1) {
      cout <<"Stack overflow! \n";
      return -1;
    }
    return arr[top--];
  }

  void traverse() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
    } else {
      for (int i = 0; i <= top; ++i) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Stack arr;
  arr.push(3);
  arr.push(4);
  arr.push(5);
  arr.pop();      // Pops 5
  arr.traverse(); // prints 3 and 4

  return 0;
}
// Output: 3 4
