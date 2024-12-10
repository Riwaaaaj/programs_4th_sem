#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *previous;
};

class DoublyLinkedList {
  Node *head;

public:
  DoublyLinkedList() { head = nullptr; }

  int countNodes() {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    return count;
  }

  void insertionBeginning(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->previous = nullptr;
    if (head == nullptr) {
      head = newNode;
      head->next = nullptr;
      return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
  }

  void deletionBeginning() {
    if (head == nullptr) {
      cout << "Empty DLL\n";
      return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
    head->previous = nullptr;
  }

  void insertionEnd(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    if (head == nullptr) {
      head = newNode;
      head->previous = nullptr;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
  }

  void deletionEnd() {
    Node *i = head;
    if (i == nullptr) {
      cout << "Empty DLL\n";
      return;
    }
    if (i->next == nullptr) {
      delete i;
      head = nullptr;
      return;
    }
    while (i->next->next != nullptr) {
      i = i->next;
    }
    delete i->next;
    i->next = nullptr;
  }
  void insertionBetween(int item, int position) {
    Node *newNode = new Node;
    newNode->data = item;
    Node *temp = head;
    int i = 2;
    while (i != position) {
      temp = temp->next;
      i++;
    }
    temp->next->previous = newNode;
    newNode->next = temp->next;
    newNode->previous = temp;
    temp->next = newNode;
  }
  void deletionBetween(int position) {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "Empty DLL\n";
      return;
    }
    if (position < 2 || position > countNodes()) {
      cout << "Invalid position.\n";
      return;
    }
    int i = 2;
    while (i != position) {
      temp = temp->next;
      i++;
    }
    temp->next->next->previous = temp;
    Node *nextAddress = temp->next->next;
    delete temp->next;
    temp->next = nextAddress;
  }

  void Searching(int key) {
    Node *temp = head;
    bool found = false;
    while (temp != nullptr) {
      if (temp->data == key) {
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
    if (head == nullptr) {
      head = obj.returnHead();
      obj.head = nullptr;
      return;
    }
    if (obj.returnHead() == nullptr) {
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = obj.returnHead();
    obj.returnHead()->previous = temp;
    obj.head = nullptr;
  }



  void traverse() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << "\n";
  }

  void interface() {
    int choice = 0, item, position, insertChoice, deleteChoice;
    while (choice != 5) {
      cout << "\nMenu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) : ";
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
    while (current != nullptr) {
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

Output when line 271 to 275 are commented out                             inputs

Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       4
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               3
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :  1
Enter item to insert:                                                       3
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               1
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       2
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               1
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  3
2 3 4
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  4
Enter item to search:                                                       2
Item found: 2
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       1
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               1
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       6
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 3 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :  1
Enter item to insert:                                                       5
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               2
Enter position to insert: 5 Menu( 1. Insert 2. Delete 3.
Traverse 4. Search 5. Exit) :                                               3
1 2 3 4 5 6
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  5
Exiting program.




Normal output:
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       2
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End: 1 Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :  1
Enter item to insert:                                                       3
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               3
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  5
Exiting program.
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  1
Enter item to insert:                                                       4
Insert at: 1. Beginning 2. Between (Position must be valid i.e not 1st or
last) 3. End:                                                               1
Menu( 1. Insert 2. Delete 3. Traverse 4. Search 5. Exit) :                  5
Exiting program.
After concatenating obj 1 and 2, we got the following result in obj1.
2 3 4
*/