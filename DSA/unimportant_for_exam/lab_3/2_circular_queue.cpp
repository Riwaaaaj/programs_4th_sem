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
      return;
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
      return -1;
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
          cout << "Queue is empty\n";
          return;
      }
      int pointer = front;
      do { 
          cout << arr[pointer] << "\t";
          pointer = (pointer + 1) % MAX_SIZE;
      } while (pointer != (rear + 1) % MAX_SIZE); 

      cout << "\n";
  }
};

int main() {
  Queue obj;
  cout << "\n1\n";
  obj.enqueue(55);
  obj.traverse();

  cout << "\n2\n";
  obj.enqueue(45);
  obj.traverse();

  cout << "\n3\n";
  obj.enqueue(25);
  obj.traverse();

  cout << "\n4\n";
  obj.dequeue();
  obj.traverse();

  cout << "\n5\n";
  obj.enqueue(35);
  obj.traverse();

  cout << "\n6\n";
  obj.dequeue();
  obj.traverse();

  cout << "\n7\n";
  obj.dequeue();
  obj.traverse();

  cout << "\n8\n";
  obj.dequeue();
  obj.traverse();

  cout << "\n9\n";
  obj.dequeue();
  

  return 0;
}
/*
1
55

2
55      45

3
55      45      25

4
45      25

5
45      25      35

6
25      35

7
35

8
Queue is empty

9
Queue underflow
*/







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
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 3
66
77
5
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 1
Enter items to enqueue: 4
Queue overflow
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Menu( 1. Enqueue 2. Dequeue 3. Traverse 4. Exit) : 2
Queue underflow*/