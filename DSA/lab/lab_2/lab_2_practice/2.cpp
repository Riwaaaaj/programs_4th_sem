#include <cstdlib>
#include <iostream>
#define MAX_SIZE 50
using namespace std;

class Stack {
  char arr[MAX_SIZE];
  int top;

public:
  Stack() { top = -1; }

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

  char returnTopItem() { 
    if (top == -1) {
      return '\0'; // Indicate empty stack
    }
    return arr[top]; 
  }

  int returnTop() { return top; }
};

int priority(char item) {
  switch (item) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
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

  int j = 0;

  for(int i = 0; infix[i] != '\0'; ++i) {
    char ch = infix[i];
    if (isalnum(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      obj.push('(');
    } else if (ch == ')') {
      while(obj.returnTopItem() != '(') {
        postfix[j++] = obj.pop();
      } 
      obj.pop();
    } else {
      if (priority(ch) > priority(obj.returnTopItem())) {
        obj.push(ch);
      } else {
        while (obj.returnTop() != -1 && priority(ch) <= priority(obj.returnTopItem())) {
          postfix[j++] = obj.pop();
        }
        obj.push(ch);
      }
    }
  }

  while (obj.returnTop() != -1) {
    postfix[j++] = obj.pop();
  }
  postfix[j] = '\0';

  cout << "Postfix: " << postfix << endl;
  return 0;
}