#include <cstdlib>
#include <iostream>
#define MAX_SIZE 50
using namespace std;

class Stack {
  char arr[MAX_SIZE];
  int top;

public:
Stack() : top(-1) {}

  void push(char item) {
    if (top == MAX_SIZE - 1) {
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

  char peek() { return arr[top]; }

  int isEmpty() { return (top == -1); }
};

int priority(char item) {
  switch (item) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}

int main() {
  Stack obj;
  char infix[MAX_SIZE], postfix[MAX_SIZE];
  cout << "Enter your infix expression: ";
  cin.getline(infix, MAX_SIZE); // This will allow us to input the entire line
                                // of text, including special characters.

  int i = 0, j = 0;
  while (infix[i] != '\0') {
    char ch = infix[i];
    if (ch == '(') {
      obj.push(ch);
    } else if (isalnum(ch)) {
      postfix[j++] = ch;
    } else if (ch == ')') {
      while (obj.peek() != '(') {
        postfix[j++] = obj.pop();
      }
      obj.pop();
    } else {
      while (priority(ch) <= priority(obj.peek()) && obj.isEmpty()) {
        postfix[j++] = obj.pop();
      }
      obj.push(ch);
    }
    i++;
  }

  while (obj.isEmpty()) {
    postfix[j++] = obj.pop();
  }

  postfix[j] = '\0';

  cout << "Postfix: " << postfix << endl;
  return 0;
}
/*
Outputs:
Enter your infix expression: A+B-C/E*(D+F)
Postfix: AB+CE/DF+*-

Enter your infix expression: (A+B)*(C-D)
Postfix: AB+CD-*

Enter your infix expression: A^(B+C)*D
Postfix: ABC+^D*
*/