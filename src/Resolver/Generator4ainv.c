#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform_random() {
  return (double)rand() / (double)RAND_MAX;
}

double step(double rnd) {
  return cbrt((2*rnd) -1);
}

double generator() {
  double uniform = uniform_random();
  printf("%f,", uniform);
  return step(uniform);
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 1000; ++i) {
    printf("%f\n", generator());
  }

  return 0;
}
