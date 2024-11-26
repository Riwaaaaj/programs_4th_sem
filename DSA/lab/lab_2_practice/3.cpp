#include <iostream>
#include <cstdlib>
#define MAX_SIZE 50
using namespace std;

class Stack {
  int top;
  char arr[MAX_SIZE];
public:
  void push(char item) {
    if (top == MAX_SIZE - 1) {
      cout << "Stack overflow \n";
      exit(1);
    }
    arr[++top] = item;
  }

  char pop() {
    if (top == -1) {
      cout << "Stack underflow \n";
      exit(1);
    }
    return arr[top--];
  }
  char returnTopItem() { 
    return arr[top]; 
  }

  int returnTop() { return top; }
}
int main() {
  
  return 0;
}