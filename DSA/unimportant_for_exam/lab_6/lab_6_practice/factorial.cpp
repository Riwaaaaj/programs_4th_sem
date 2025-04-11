#include<iostream>
using namespace std;

int factorial(int n) {
  if(n == 0)
    return 1;
  return n * factorial(n-1);
}

int main() {
  int fac3 = factorial(3);
  cout << fac3 << "\n";
  return 0;
}
