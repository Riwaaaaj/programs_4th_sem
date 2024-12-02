#include <iostream>
#include <cmath>
using namespace std;

// #define f(x) sin(x) - 1.0 / x

inline float f(float x) {
  return sin(x) - 1.0 / x;
}



int main() {
  float a = 2, b = 1, e = 0.000001, steps = 0;

  cout << "Enter two inital guesses." << endl;
  cin >> a >> b;

  cout << "Enter tolerable error." << endl;
  cin >> e;
  
  float c;

  cout << "\t\t" << "steps" << "\t" << "a" << "\t" << "b" << "\t" << "c" << "\t" << "f(c)" << endl;
  do { // here fabs is the absolute value function
    c = b - f(b) * (b - a) / (f(b) - f(a));
    steps++;
    cout << "\t\t" << steps << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;
    a = b;
    b = c;
  } while(fabs(f(c)) > e);

  cout << "Result = " << c << endl;
  return 0;
}
/*
Enter two inital guesses.
1 2
Enter tolerable error.
0.01
                steps   a       b       c       f(c)
                1       1       2       1.27919 0.176035
                2       2       1.27919 0.735213        -0.689404
                3       1.27919 0.735213        1.16854 0.06441
                4       0.735213        1.16854 1.13151 0.0212845
                5       1.16854 1.13151 1.11324 -0.00114511
Result = 1.11324
*/