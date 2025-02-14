#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *previous;
};

class Queue {
  Node *front;

public:
  Queue() { front = nullptr; }

  void enqueue(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->previous = nullptr;
    if (front == nullptr) {
      front = newNode;
      front->next = nullptr;
      return;
    }
    newNode->next = front;
    front->previous = newNode;
    front = newNode;
  }

  void dequeue() {
    Node *temp = front;
    if (temp == nullptr) {
      cout << "Empty Queue\n";
      return;
    }
    if (temp->next == nullptr) {
      delete temp;
      front = nullptr;
      return;
    }
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  void traverse() {
    Node *temp = front;
    cout << "Queue traverse\n";
    while (temp != nullptr) {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << "\n";
  }

  void menu() {
    int choice = 0, item, position, insertChoice, deleteChoice;
    while (choice != 4) {
      cout << "Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) : \n";
      cin >> choice;

      switch (choice) {

      case 1:
        cout << "Enter item to insert: ";
        cin >> item;
        enqueue(item);
        break;

      case 2:
        dequeue();
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
  ~Queue() {
    Node *current = front;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }
};
int main() {
  Queue obj;
  obj.menu();
  return 0;
}
/*
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
1
Enter item to insert: 4
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
2
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
2
Empty Queue
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
1
Enter item to insert: 5
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
1
Enter item to insert: 6
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
1
Enter item to insert: 7
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
2
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
3
Queue traverse
7       6
Menu( 1.Enqueue 2.Dequeue 3.Traverse 4.Exit) :
4
Exiting program.
*/