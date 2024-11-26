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
      exit(1);
    }
    if (front == - 1) {
      front = 0;
    }
    arr[++rear] = item;
  }

  int dequeue() {
    if (front == -1 || front > rear) {
      cout << "Queue overflow\n";
      exit(1);
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
      exit(1);
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
  int choice, item;
  // bool p = false;
  while (choice != 4) {
    cout << "Menu: \n 1. Enqueue \n 2. Dequeue \n 3. Traverse \n 4. Exit \n";
    cin >> choice;
    switch(choice) {
    case 1:
      cout << "Enter items to enqueue: ";
      cin >> item;
      obj.enqueue(item);
    case 2:
      obj.dequeue();
    case 3:
      obj.traverse();
    case 4:
    default:
      cout << "Invalid input. \n";
    }
  }
  return 0;
}