#ifndef __GEN_H__
#define __GEN_H__

#include <climits>
#include <cstdlib>
#include <cmath>
#include <exception>

struct errorRand : std::exception {
  const char* what() const throw() {return "Error generating random number\n";}
};

//static unsigned ix = 1;
double Random(void) {
  /*ix = ix * 69069L + 1;
  return ix / ((double)ULONG_MAX + 1);*/
  return rand()*1.0/RAND_MAX; //TODO
}

double Exponential(double t) {
  return -t * std::log(Random());
}

double Uniform(double i1, double i2) {
  if (i1 > i2)
    throw new errorRand;

  return (Random() * (i2 - i1)) + i1;
}

double Normal(double mi, double sigma) {
  double sum = 0.0;
  for (int i = 0; i < 12; ++i)
    sum += Random();

  return (sum - 6.0)*sigma+mi;
}
#endif // __GEN_H__
