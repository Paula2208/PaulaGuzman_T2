#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Piecewise distribution

double uniform_random() {
  //Generate random Uniform variable between 0 and 1
  return (double)rand() / (double)RAND_MAX;
}

double first_section(double rnd) {
  //As defined on document
  return (5.0/4.0) + sqrt((25.0/16.0) - (2*rnd));
}

double second_section(double rnd) {
  //As defined on document
  return (4*rnd) - 2;
}

double generator() {
  //Generates a new random variate
  double uniform = uniform_random();
  printf("%f,", uniform);
  if (uniform <= 0.75) {
    return first_section(uniform);
  }
  return second_section(uniform);
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 1000; ++i) {
    printf("%f,,\n", generator());
  }

  return 0;
}
