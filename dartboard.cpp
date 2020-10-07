#include <iostream>
#include <math.h>
//#include <string.h>
#include <string>
#include "timer.hh"
#include <time.h>

#define SEED 35791246

using namespace std;

double dartboardPI(int ndarts)
{
  double x, y;
  int i, count = 0;
  double z;
  double pi;
  for (i = 0; i < ndarts; i++)
  {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if (z <= 1)
      count++;
  }
  pi = (double)count / ndarts * 4;
  return pi;
}

int dartboard(int ndarts)
{
  double x, y;
  int i, count = 0;
  double z;

  for (i = 0; i < ndarts; i++)
  {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if (z <= 1)
      count++;
  }

  return count;
}

long double dartboardAveragePI(int niter, int ndarts)
{
  double avg = 0, pi;

  for (int i = 0; i < niter; i++)
  {
    avg += dartboard(ndarts);
  }
  pi = (long double)avg / niter / ndarts * 4;
  return pi;
}

main(int argc, char **argv)
{
  int niter = stoi(argv[1]);
  int ndarts = stoi(argv[2]);
  double base_pi = 3.14159, err;
  long double pi;
  srand(time(NULL));
  Timer t;
  pi = dartboardAveragePI(niter, ndarts);
  int nt = t.elapsed();
  err = abs(base_pi - pi);

  cout << ndarts << "\t" << nt << "\t" << pi << "\t";
}