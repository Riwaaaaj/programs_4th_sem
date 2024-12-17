#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};
class Stack {
  Node *top;

public:
  Stack() { top = NULL; }
  void push(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = top;
    top = newNode;
  }
  void pop() {
    if (top == NULL) {
      cout << "Empty Stack\n";
      return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
  }
  void traverse() {
    Node *temp = top;
    cout << "Stack traverse\n";
    while (temp != NULL) {
      cout << temp->data << "\n";
      temp = temp->next;
    }
  }
  void menu() {
    int choice = 0, item, position, insertChoice, deleteChoice;
    while (choice != 4) {
      cout << "Menu( 1.Push 2.Pop 3.Traverse 4.Exit) : \n";
      cin >> choice;

      switch (choice) {
      case 1:
        cout << "Enter item to insert: ";
        cin >> item;
        push(item);
        break;

      case 2:
        pop();
        break;

      case 3:
        traverse();
        break;

      case 4:
        cout << "Exiting program.\n";
        break;

      default:
        cout << "Invalid input.\n";
      }
    }
  }
  ~Stack() {
    Node *current = top;
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }
};
int main() {
  Stack obj;
  obj.menu();
  return 0;
}
/*
Output:
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
2
Empty Stack
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
1
Enter item to insert: 5
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
1
Enter item to insert: 6
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
1
Enter item to insert: 7
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
2
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
3
Stack traverse
6
5
Menu( 1.Push 2.Pop 3.Traverse 4.Exit) :
4
Exiting program.
*/