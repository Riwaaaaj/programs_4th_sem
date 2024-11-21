#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// #define f(x) sin(x) - 1.0 / x

inline float f(float x) {
  return sin(x) - 1.0 / x;
}



int main() {
  float a, b;

  cout << "Enter two inital guesses." << endl;
  cin >> a >> b;

  if (f(a) * f(b) > 0) {
    cout << "Your two inital guesses has same sign of their corresponding function. " << endl;
    exit(1);
  }

  if(f(a) > f(b)) {
    float temp;
    temp = a;
    a = b;
    b = temp;
  }

  float c;

  do { 
    c = (b * f(a) - a * f(b)) / (f(a) - f(b));
    if( f(c) > 0) {
      b = c;
    } else if ( f(c) < 0) {
      a = c;
    }
  } while(fabs(f(c)) > 0.0001); // here fabs is the absolute value function

  cout << "Result = " << c << endl;
  return 0;
}