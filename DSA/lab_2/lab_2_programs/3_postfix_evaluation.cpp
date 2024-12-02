#include <cmath> // for pow function
#include <cstdlib>
#include <iostream>
#define MAX_SIZE 50
using namespace std;

class Stack {
  int arr[MAX_SIZE];
  int top;

public:
  Stack() { top = -1; }
  void push(int item) {
    if (top == MAX_SIZE - 1) {
      cout << "Stack overflow" << endl;
      exit(1);
    }
    arr[++top] = item;
  }

  int pop() {
    if (top == -1) {
      cout << "Stack underflow" << endl;
      exit(1);
    }
    return arr[top--];
  }

  bool isEmpty() { return top == -1; }
};

int main() {
  Stack obj;
  char postfix[MAX_SIZE];
  cout << "Enter your postfix expression: ";
  cin.getline(postfix, MAX_SIZE);

  int i = 0;
  while (postfix[i] != '\0') {
    char ch = postfix[i];

    // Checks if the character is a digit.
    if (isdigit(ch)) {
      obj.push(ch - '0'); // Converts char to int
    } else {
      if (obj.isEmpty()) {
        cout << "Error: Insufficient operands for operator '" << ch << "'"
             << endl;
        exit(1);
      }
      int a = obj.pop();

      if (obj.isEmpty()) {
        cout << "Error: Insufficient operands for operator '" << ch << "'"
             << endl;
        exit(1);
      }
      int b = obj.pop();
      switch (ch) {
      case '+':
        obj.push(b + a);
        break;
      case '-':
        obj.push(b - a);
        break;
      case '*':
        obj.push(b * a);
        break;
      case '/':
        if (a == 0) {
          cout << "Division by zero error. Exiting..." << endl;
          exit(1);
        }
        obj.push(b / a);
        break;
      case '^':
        obj.push(pow(b, a));
        break;
      default:
        cout << "Wrong character was given i.e. '" << ch << "'. Exiting ..."
             << endl;
        exit(1);
      }
    }
    i++;
  }
  cout << "Final result: " << obj.pop() << endl;

  return 0;
}

/*
Outputs:
Enter your postfix expression: 56+34-*72/+
Final result: -8

Enter your postfix expression: 23+
Final result: 5

Enter your postfix expression: 92-
Final result: 7
*/