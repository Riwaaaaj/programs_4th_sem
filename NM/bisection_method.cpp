#include <iostream>
#include <cmath>
using namespace std;
#define f(x) pow(x, 3) - 4 * x - 9
int main() {
  float a, b , e, steps = 0;
  cout << "Enter two inital guesses." << endl;
  cin >> a >> b;
  cout << "Enter tolerable error." << endl;
  cin >> e;

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
  cout << "\t\t" << "steps" << "\t" << "a" << "\t" << "b" << "\t" << "c" << "\t" << "f(c)" << endl;
  do { // Here fabs is the absolute value function
    c = (a + b) / 2;
    steps++;
    cout << "\t\t" << steps << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;
    if( f(c) > 0) {
      b = c;
    } else if ( f(c) < 0) {
      a = c;
    }
  } while(fabs(f(c)) > e);
  cout << "\t" <<  "Result = " << c << endl;
  return 0;
}
/*Enter two inital guesses.
2 3
Enter tolerable error.
0.01
                steps   a       b       c       f(c)
                1       2       3       2.5     -3.375
                2       2.5     3       2.75    0.796875
                3       2.5     2.75    2.625   -1.41211
                4       2.625   2.75    2.6875  -0.339111
                5       2.6875  2.75    2.71875 0.220917
                6       2.6875  2.71875 2.70312 -0.0610771
                7       2.70312 2.71875 2.71094 0.0794234
                8       2.70312 2.71094 2.70703 0.00904924
        Result = 2.70703 */