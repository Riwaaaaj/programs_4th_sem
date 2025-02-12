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
      return -1;
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
  obj.enqueue(55);
  obj.enqueue(45);
  obj.enqueue(25);
  obj.dequeue();
  obj.traverse();

  return 0;
}//output 45, 25

// int main() {
//   Queue obj;
//   int choice = 0, item;
//   while (choice != 4) {
//     cout << "Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : ";
//     cin >> choice;
//     switch(choice) {
//     case 1:
//       cout << "Enter items to enqueue: ";
//       cin >> item;
//       obj.enqueue(item);
//       break;
//     case 2:
//       obj.dequeue();
//       break;
//     case 3:
//       obj.traverse();
//       break;
//     case 4: break;
//     default:
//       cout << "Invalid input. \n";
//     }
//   }
//   return 0;
// }

/*
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Queue underflow
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 1
Enter items to enqueue: 55
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 1
Enter items to enqueue: 66
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 1
Enter items to enqueue: 77
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 3
66
77
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 1
Enter items to enqueue: 5
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 3
77
5
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 4



*/
