
//Lagrange's interpolation

#include <stdio.h>
#define MAX_SIZE 3

float recursion1(float x[], float y[], int n, float targetX, int i) {
  return recursion1(n, i);
}
float fun(float x[], float y[], int n, float targetX) {
  float sum = 0;
  int i;
  for(i = 0; i < MAX_SIZE; ++i) {
    for(int j = 0; j < MAX_SIZE; ++j) {
      if(i == j) {
        return 1;
      }
      numerator = recursion1(x, y, n, targetX, i);
      // denominator = 
    }
  }
}

int main() {
  float x[MAX_SIZE], y[MAX_SIZE], resultY;
  int i;
  for(i = 0 ; i < MAX_SIZE; ++i) {
    printf("Enter x[%d] \n", i + 1);
    scanf("%f", &x[i]);
    printf("Enter y[%d] \n", i + 1);
    scanf("%f", &y[i]);
  }
  float targetX;
  printf("Enter the value of x for interpolation: ");
  scanf("%f", &targetX);

  resultY = fun(x, y, MAX_SIZE, targetX);

  return 0;
}