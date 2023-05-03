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
  //As defined in document
  return sqrt(2.0 * (rnd + 32.0));
}

double second_section(double rnd) {
  //As defined in document
  return sqrt((-2.0*rnd)+81.0);
}

double generator() {
  //Gives a random variate
  double uniform1 = uniform_random();
  double uniform2 = uniform_random();
  printf("%f,", uniform2);
  if(uniform1 <= 1.0/2.0){
    return first_section(uniform2);
  }
  return second_section(uniform2);
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 1000; ++i) {
    printf("%f\n", generator());
  }

  return 0;
}
