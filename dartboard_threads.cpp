#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
#include "timer.hh"
#include "ThreadPool.hh"
#include <math.h>
#include "timer.hh"
#include <time.h>
#include <typeinfo>

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
  pi = (double)(count / ndarts) * 4;
  return pi;
}

int dartboard(int ndarts)
{
  srand(getpid() * time(NULL));
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

void dartboardAveragePI(int niter, int ndarts, long double *lista, size_t index)
{
  double avg = 0, pi;

  for (int i = 0; i < niter; i++)
  {
    avg += dartboard(ndarts / 4);
  }
  pi = (long double)(avg / niter / (ndarts / 4)) * 4;
  lista[index] = pi;
  //cout << pi << " ";
}

main(int argc, char **argv)
{
  int niter = stoi(argv[1]);
  int ndarts = stoi(argv[2]);
  //int nn = (int)ndarts / 10000;
  double base_pi = 3.14159, err;
  long double *lista = (long double *)malloc(4 * sizeof(long double));
  Timer t;
  {
    ThreadPool pool(4);
    for (size_t c = 0; c < 4; c++)
      pool.enqueue([&lista, niter, ndarts, c]() { dartboardAveragePI(niter, ndarts, ref(lista), c); });
  }
  long double pi = 0;
  for (int i = 0; i < 4; i++)
  {
    //cout << lista[i] << endl;
    pi += lista[i];
  }

  cout << t.elapsed() << "\t" << pi / 4 << endl;
}