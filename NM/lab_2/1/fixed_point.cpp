#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

inline double f(double x) {
  return sin(x) - 1.0 / x;
}

inline double g(double x) {
    return x - f(x); 
}

int main() {
  double a, x, e;

  cout << "Enter inital guesses: ";
  cin >> a;
  cout << "Enter tolerable error." << endl;
  cin >> e;
  x = f(a);
  
  return 0;
}