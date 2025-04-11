#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
  int data;
  Node* next;
};

class LinkedList {
  Node *head;
public:
  LinkedList() : head(nullptr){}
  void insertionBeginning(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
  }
  void deletionBeginning() {
    if(head == nullptr) {
      cout << "Empty SLL\n";
      return;
    }
    Node* temp2 = head;
    head = head->next;
    delete temp2;
  }

  void insertionEnd(int item) { 
    Node* newNode = new Node;  
    newNode->data = item;
    newNode->next = NULL;
    if (head == NULL) {
      head = newNode;
      return;
    }
    Node* temp2 = head;
    while(temp2->next != NULL) {
      temp2 = temp2->next;
    }
    temp2->next = newNode;
  }

  void deletionEnd() { //review
    if(head == nullptr) {
      cout << "Empty SLL\n";
      return;
    }
    if(head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp2 = head;
    while (temp2->next->next != nullptr) {
      temp2 = temp2 -> next;
    }
    delete temp2->next;
    temp2->next = nullptr;
  }
  void insertionBetween(int item, int position) {//review
    Node *newNode = new Node;
    newNode->data = item;
    Node *temp2 = head;
    int i = 2;
    while (i != position) {
      temp2 = temp2 -> next;
      i++;
    }
    newNode->next = temp2->next;
    temp2->next = newNode;
  }
  void deletionBetween(int position) { //review
    if(head == nullptr) {
      cout << "Empty SLL\n";
      return;
    }
    if(head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp2 = head;
    int i = 2;
    while (i != position) {
      temp2 = temp2 -> next;
      i++;
    }
    Node *nextPosition;
    temp2->next->next == nullptr? nextPosition = nullptr: nextPosition = temp2->next->next;
    delete temp2->next;
    temp2->next = nextPosition;
  }

  void traverse() {
    Node *temp2 = head;
    while(temp2 != nullptr) {
      cout << temp2->data << "\n";
      temp2 = temp2 -> next;
    }
  }
  void Searching(int item) {
    Node *temp2 = head;
    bool found = false;
    while(temp2 != nullptr) {
      if (temp2->data == item) {
        found = true;
        break; // exit loop ensuring that temp2 is not updated anymore
      } 
      temp2 = temp2 -> next;
    }
    if (!found) {
        cout << "Item not found \n";
      } else {
          cout << "Item found: " << temp2->data << "\n";
      }
  }

  ~LinkedList() {
    Node* temp1 = head;
    while (temp1 != nullptr) {
      Node* temp2 = temp1;
      temp1 = temp1->next;
      delete temp2;
    }
  }
};

int main() {
  LinkedList obj;
  obj.insertionBeginning(10);
  obj.insertionBeginning(20);
  obj.insertionBeginning(30);
  obj.insertionEnd(5);
  obj.insertionBetween(15,3);
  obj.deletionBeginning();
  obj.deletionEnd();
  obj.deletionBetween(2);
  obj.traverse();
  obj.Searching(10);

  
  return 0;
}
/*
20
10
Item found: 10
*/