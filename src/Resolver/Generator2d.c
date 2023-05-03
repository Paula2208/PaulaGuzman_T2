#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Polygon distribution

double uniform_random() {
  //Generate random Uniform variable between 0 and 1
  return (double)rand() / (double)RAND_MAX;
}

double first_section(double rnd, double a, double b, double c) {
  //As defined in document
  return sqrt(rnd * 2 * a);
}

double second_section(double rnd, double a, double b, double c) {
  //As defined in document
  return rnd - a;
}

double third_section(double rnd, double a, double b, double c) {
  //As defined in document
  return sqrt(b*b - (rnd * (2*a)));
}

double generator(double a, double b, double c) {
  //Gives a random variate
  double uniform1 = uniform_random();
  double uniform2 = uniform_random();
  double coeff = 2.0/(c-a);
  printf("%f,", uniform2);
  if(uniform1 < coeff){
    return first_section(uniform2, a, b, c);
  }
  else if(uniform1 == coeff){
    return second_section(uniform2, a, b, c);
  }
  return third_section(uniform2, a, b, c);
}

int main() {
  srand(time(NULL));

  const double a = 1.0, b = 2.0, c = 3.0;

  for (int i = 0; i < 1000; ++i) {
    printf("%f\n", generator(a, b, c));
  }

  return 0;
}
