#include <iostream>
#include <cmath> // for pow and fabs function.
#include <cstdlib> // for exit function.
using namespace std;
#define f(x) pow(x, 3.0) - 4.0 * x - 9.0 // defining the function f(x)
int main() {
  float a, b, e;
  cout << "Enter two inital guesses." << endl;
  cin >> a >> b;
  cout << "Enter tolerable error." << endl;
  cin >> e;

  if (f(a) * f(b) > 0) { // f(a) and f(b) must have alternate sign.
    cout << "Your two inital guesses has same sign of their corresponding function. " << endl;
    exit(1); //Terminating the program with the error 1.
  }
  if(f(a) > f(b)) { // Making sure that f(a) is -ve and f(b) is +ve as in line 29, b is replaced
    float temp;     // by c when f(c) is +ve and vice versa.
    temp = a;
    a = b;
    b = temp;
  }
  float c, steps = 0;
  cout << "\t\t" << "steps" << "\t" << "a" << "\t" << "b" << "\t" << "c" << "\t" << "f(c)" << endl;
  do { 
    c = (a + b) / 2;
    steps++;
    cout << "\t\t" << steps << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;
    if( f(c) > 0) {
      b = c;
    } else if ( f(c) < 0) {
      a = c;
    }
  } while(fabs(f(c)) > e); // Here, fabs is the absolute value function
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

        // Start
        // Define function f(x)
        // Enter two initial guesses and error (say a, b and e)
        // if (f(a) * f(b) > 0)
        //   print "f(a) and f(b) must have alternate sign." and exit
        // if (f(a) > f(b))
        //   exchange their values to make sure f(a) is -ve and f(b) is +ve
        // do {
        //   c = (a + b) * 0.5
        //   if( f(c) > 0) {
        //     b = c
        //   } else if ( f(c) < 0) {
        //     a = c
        // } while (fabs(f(c)) > e)
        // Print c
        // Exit