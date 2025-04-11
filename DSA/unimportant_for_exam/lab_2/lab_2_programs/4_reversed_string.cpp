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

  bool isEmpty() { return top == -1; }
};
int main() {
  Stack obj;
  char str[MAX_SIZE];
  cout << "Enter the string: ";
  cin.getline(str, MAX_SIZE);

  int i = 0;
  while (str[i] != '\0') {
    obj.push(str[i]);
    i++;
  }

  cout << "Reversed string: ";
  while (!obj.isEmpty()) {
    cout << obj.pop();
  }
  cout << endl;

  return 0;
}
// Enter the string: Riwaj
// Reversed string: jawiR