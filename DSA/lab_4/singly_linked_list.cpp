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
  LinkedList() {head = NULL;}
  void insertionBeginning(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
  }
  void deletionBeginning() {
    if(head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  void insertionEnd(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp -> next;
    }
    temp->next = newNode;
  }
  void deletionEnd() {
    if(head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    if(head->next == NULL) {
      delete head;
      head = NULL;
      return;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
      temp = temp -> next;
    }
    delete temp->next;
    temp->next = NULL;
  }
  void insertionBetween(int item, int position) {//3
    Node *newNode = new Node;
    newNode->data = item;
    Node *temp = head;
    int i = 2;
    while (i != position) {
      temp = temp -> next;
      i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
  void deletionBetween(int position) {
    if(head == NULL) {
      cout << "Empty SLL\n";
      return;
    }
    if(head->next == NULL) {
      delete head;
      head = NULL;
      return;
    }
    Node *temp = head;
    int i = 2;
    while (i != position) {
      temp = temp -> next;
      i++;
    }
    Node *nextPosition;
    temp->next->next == NULL? nextPosition = NULL: nextPosition = temp->next->next;
    delete temp->next;
    temp->next = nextPosition;
  }

  void traverse() {
    Node *temp = head;
    while(temp != NULL) {
      cout << temp->data << "\n";
      temp = temp -> next;
    }
  }
  void Searching(int item) {
    Node *temp = head;
    bool found = false;
    while(temp != NULL) {
      if (temp->data == item) {
        found = true;
        break; // exit loop ensuring that temp is not updated anymore
      } 
      temp = temp -> next;
    }
    if (!found) {
        cout << "Item not found \n";
      } else {
          cout << "Item found: " << temp->data << "\n";
      }
  }

  ~LinkedList() {
    Node* current = head;
    while (current != NULL) {
      Node* temp = current;
      current = current->next;
      delete temp;
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