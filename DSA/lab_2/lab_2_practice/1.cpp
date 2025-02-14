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
  }
  int pop() {
  }
  void traverse() {
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