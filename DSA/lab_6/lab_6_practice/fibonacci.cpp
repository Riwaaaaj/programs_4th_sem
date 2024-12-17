#include<iostream>
using namespace std;

void fibonacci(int n1, int n2, int iteration) {
  cout << n1 + n2 << "\t"; // 2 + 3 = 5
  iteration--;// 1
  int temp = n1; // temp = 3
  n1 = n2; // n1 = 5
  n2 = temp + n2;// n2 = 8

  if(iteration == 1) {
    cout << n1 + n2 << "\t";
    return;
  }

  return fibonacci(n1, n2, iteration);
}

int main() {
  int n1 = 2, n2 = 3, iteration = 4;
  cout << n1 << "\t";
  cout << n2 << "\t";
  fibonacci(n1, n2, iteration);
  return 0;
}
