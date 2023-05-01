#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform_random() {
  return (double)rand() / (double)RAND_MAX;
}

double first_step(double rnd) {
  return (5.0/4.0) + sqrt((25.0/16.0) - (2*rnd));
}

double second_step(double rnd) {
  return (4*rnd) - 2;
}

double generator() {
  double uniform = uniform_random();
  printf("%f,", uniform);
  if (uniform <= 0.75) {
    return first_step(uniform);
  }
  return second_step(uniform);
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 1000; ++i) {
    printf("%f,,\n", generator());
  }

  return 0;
}
