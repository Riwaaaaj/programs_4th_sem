//What are the functions required inside and outside the class?
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
    
  }

  char pop() {
    
  }

};

int priority(char item) {

}

int main() {
  Stack obj;
  char infix[MAX_SIZE], postfix[MAX_SIZE];
  cout << "Enter your infix expression: ";
  

  cout << "Postfix: " << postfix << endl;
  return 0;
}