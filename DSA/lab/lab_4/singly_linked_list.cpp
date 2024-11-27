#include <iostream>
#include <cstdlib>
#define MAX_SIZE 4
using namespace std;

class Node {
public:
  int data;
  Node* next;
};

class LinkedList {
  Node array[Max_size];
  Node *head = new Node;
  LinkedList() {
    head = array[0];
  }
public:

  void insersionBeggining(int item) {
    if (head.next == NULL) {
      head.data = item;
      head.next = *array[1];
    }
  }
}
int main() {
  
  return 0;
}