#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Triangular distribution

double uniform_random() {
  //Generate random Uniform variable between 0 and 1
  return (double)rand() / (double)RAND_MAX;
}

double first_section(double rnd, double a, double b, double c) {
  //As defined on document
  return sqrt(rnd * (c-a) * (b-a)) + a;
}

double second_section(double rnd, double a, double b, double c) {
  //As defined on document
  return c - sqrt((1.0-rnd) * (c-a) * (c-b));
}

double generator(double a, double b, double c) {
  //Gives a random variate
  double uniform = uniform_random();
  printf("%f,", uniform);
  if (uniform <= (b-a)/(c-a)) {
    return first_section(uniform, a, b, c);
  }
  return second_section(uniform, a, b, c);
}

int main() {
  srand(time(NULL));

  const double a = 1.0, b = 2.0, c = 3.0;

  for (int i = 0; i < 1000; ++i) {
    printf("%f\n", generator(a, b, c));
  }

  return 0;
}
