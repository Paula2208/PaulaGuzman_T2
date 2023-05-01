#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform_random() {
  return (double)rand() / (double)RAND_MAX;
}

double first_step(double rnd) {
  return 0.0;
}

double second_step(double rnd, double a, double b, double c) {
  return sqrt(rnd * (c-a) * (b-a)) + a;
}

double third_step(double rnd, double a, double b, double c) {
  return c - sqrt((1.0-rnd) * (c-a) * (c-b));
}

double fourth_step() {
  return 1.0;
}

double generator(double a, double b, double c) {
  double uniform = uniform_random();
  printf("%f,", uniform);
  if (uniform <= (b-a)/(c-a)) {
    return second_step(uniform, a, b, c);
  }
  return third_step(uniform, a, b, c);
}

int main() {
  srand(time(NULL));

  const double a = 1.0, b = 2.0, c = 3.0;

  for (int i = 0; i < 1000; ++i) {
    printf("%f\n", generator(a, b, c));
  }

  return 0;
}
