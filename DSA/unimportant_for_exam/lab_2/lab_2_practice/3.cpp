#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define max 50

class Stack {
  char arr[max];
  int top;
  public:
    Stack() : top(-1) {}

    void push(char item) {
      if (top == max - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
      }
      arr[++top] = item;
    }

    char pop() {
      if (top == -1) {
        cout << "Stack underflow" << endl;
        exit(1);
      }
      return arr[top--];
    }

    char isEmpty() { return top;}
};

int main() {
  Stack obj;
  char postfix[max];
  cout << "Enter your postfix expression: ";
  cin.getline(postfix, max);


  return 0;
}