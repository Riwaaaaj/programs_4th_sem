#include <cstdlib>
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node* previous;
};

class DoublyLinkedList {
  Node *head;

public:
  DoublyLinkedList() {
    head = NULL;
    head->previous = NULL;
  }
  void insertionBeginning(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
  }
  void deletionBeginning() {
    if (head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  void insertionEnd(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    if (head == NULL) {
      newNode->next = head;
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
  void deletionEnd() {
    if (head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    if (head->next == NULL) {
      delete head;
      head = NULL;
      return;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
  }
  void insertionBetween(int item, int position) { // 3
    Node *newNode = new Node;
    newNode->data = item;
    Node *temp = head;
    int i = 2;
    while (i != position) {
      temp = temp->next;
      i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
  void deletionBetween(int position) {
    if (head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    if (head->next == NULL) {
      delete head;
      head = NULL;
      return;
    }
    Node *temp = head;
    int i = 2;
    while (i != position) {
      temp = temp->next;
      i++;
    }
    Node *nextPosition;
    temp->next->next == NULL ? nextPosition = NULL
                             : nextPosition = temp->next->next;
    delete temp->next;
    temp->next = nextPosition;
  }

  void traverse() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << "\n";
      temp = temp->next;
    }
  }
  void Searching(int item) {
    Node *temp = head;
    bool found = false;
    while (temp != NULL) {
      if (temp->data == item) {
        found = true;
        break; // exit loop ensuring that temp is not updated anymore
      }
      temp = temp->next;
    }
    if (!found) {
      cout << "Item not found \n";
    } else {
      cout << "Item found: " << temp->data << "\n";
    }
  }
  Node *returnHead() { return head; }
  void concatenate(DoublyLinkedList &obj) {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = obj.returnHead();
    obj.head = NULL;
  }

  void interface() {
    int choice = 0, item, position, insertChoice, deleteChoice;
    while (choice != 5) {
      cout << "Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : ";
      cin >> choice;

      switch (choice) {
      case 1:
        cout << "Enter item to insert: ";
        cin >> item;
        cout << "Insert at: 1. Beginning 2. Between (Position must be valid "
                "i.e not 1st or last) 3. End: ";
        cin >> insertChoice;

        switch (insertChoice) {
        case 1:
          insertionBeginning(item);
          break;
        case 2:
          cout << "Enter position to insert: ";
          cin >> position;
          insertionBetween(item, position);
          break;
        case 3:
          insertionEnd(item);
          break;
        default:
          cout << "Invalid insertion choice.\n";
        }
        break;

      case 2:
        cout << "Delete from: 1. Beginning 2. Between (Position must be valid "
                "i.e not 1st or last) 3. End: ";
        cin >> deleteChoice;

        switch (deleteChoice) {
        case 1:
          deletionBeginning();
          break;
        case 2:
          cout << "Enter position to delete: ";
          cin >> position;
          deletionBetween(position);
          break;
        case 3:
          deletionEnd();
          break;
        default:
          cout << "Invalid deletion choice.\n";
        }
        break;

      case 3:
        traverse();
        break;

      case 4:
        cout << "Enter item to search: ";
        cin >> item;
        Searching(item);
        break;

      case 5:
        cout << "Exiting program.\n";
        break;

      default:
        cout << "Invalid input.\n";
      }
    }
  }
  ~DoublyLinkedList() {
    Node *current = head;
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }
};
int main() {
  DoublyLinkedList obj1, obj2;

  obj1.interface();
  obj2.interface();
  obj1.concatenate(obj2);
  cout << "After concatenating obj 1 and 2, we got the following result in "
          "obj1.\n";
  obj1.traverse();
  return 0;
}
/*
Output when line 213 to 216 is commented.
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 3
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 3 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 2
Delete from: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 3 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 3
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 4
Enter item to search: 3
Item found: 3
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 4
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 7
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 2 Enter position to insert: 2 Menu( 1. Insert 2. Delete 3.
Traverse 4. Search 5. Exit) : 3
4
7
3
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 5
Exiting program.

Final output:
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 10
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 20
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 5
Exiting program.
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 3
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 1
Enter item to insert: 4
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : 5
Exiting program.
After concatenating obj 1 and 2, we got the following result in obj1.
20
10
4
3
*/