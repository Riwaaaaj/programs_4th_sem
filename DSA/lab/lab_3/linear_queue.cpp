#include <iostream>
#include <cstdlib>
#define MAX_SIZE 50
using namespace std;

class Queue {
  int arr[MAX_SIZE];
  int front, rear;

public:
  Queue() { front = -1, rear = -1; }

  void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
      cout << "Queue overflow\n";
      return;
    }
    if (front == - 1) {
      front = 0;
    }
    arr[++rear] = item;
  }

  int dequeue() {
    if (front == -1 || front > rear) {
      cout << "Queue underflow\n";
      return;
    }
    int item = arr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {

    front++;
    }
  return item;
  }

  void traverse() {
    if (front == -1) {
      cout << "Queue is empty \n";
      return;
    }
    int pointer = front;
    while (pointer <= rear) {
      cout << arr[pointer] << "\n";
      pointer++;
    }

  }
};

int main() {
  Queue obj;
  int choice = 0, item;
  // bool p = false;
  while (choice != 4) {
    cout << "Menu: \n 1. Enqueue \n 2. Dequeue \n 3. Traverse \n 4. Exit \n";
    cin >> choice;
    switch(choice) {
    case 1:
      cout << "Enter items to enqueue: ";
      cin >> item;
      obj.enqueue(item);
      break;
    case 2:
      obj.dequeue();
      break;
    case 3:
      obj.traverse();
      break;
    case 4: break;
    default:
      cout << "Invalid input. \n";
    }
  }
  return 0;
}