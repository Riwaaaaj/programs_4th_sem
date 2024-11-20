#include <iostream>
using namespace std;

class Complex {
  float real, imag;
public:
  friend void display();
};

void display() {
  Complex c;
    //  cout << c.real << " + j" << c.imag << endl;
   cout << "Enter real and imaginary: ";
   cin >> c.real >> c.imag;
   cout << c.real << " + j" << c.imag << endl;
}

int main() {
  display();
  display();
  return 0;
}
