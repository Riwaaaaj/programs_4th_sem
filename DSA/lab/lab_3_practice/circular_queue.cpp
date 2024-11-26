#include <iostream>
#include <cstdlib>
#define MAX_SIZE 3
using namespace std;

class Queue {
  int arr[MAX_SIZE];
  int front, rear;

public:
  Queue() { front = -1, rear = -1; }

  void enqueue(int item) {
    if ((rear + 1) % MAX_SIZE == front) {
      cout << "Queue overflow\n";
      exit(1);
    }
    if (front == - 1) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = item;
  }

  int dequeue() {
    if (front == -1) {
      cout << "Queue underflow\n";
      exit(1);
    }
    int item = arr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % MAX_SIZE;
    }
  return item;
  }

  void traverse() {
    if (front == -1) {
      cout << "Queue is empty \n";
    }
    int pointer = front;
    while (pointer != rear) {
      cout << arr[pointer] << "\n";
      pointer = (pointer + 1) % MAX_SIZE;
    }
    cout << arr[pointer] << "\n";
  }
};

int main() {
  Queue obj;
  obj.enqueue(3);
  obj.enqueue(4);
  obj.enqueue(5);
  obj.dequeue();
  obj.enqueue(6);
  obj.traverse();

  return 0;
}