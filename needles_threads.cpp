#include <iostream>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <time.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <wait.h>
#include "ThreadPool.hh"
#include "timer.hh"

using namespace std;

void calc(int n, long double *result, size_t index)
{
  srand(getpid() * time(NULL));
  double x;
  double y;
  double d;
  double P = 0;

  for (int i = 0; i < 10000; i++)
  {
    x = ((double)rand() / RAND_MAX) * 3.1415;
    d = ((double)rand() / RAND_MAX);
    y = 0.5 * sin(x);
    if (d <= y)
    {
      P++;
    }
  }
  result[index] = (long double)10000 / P;
}

int main(int argc, char **argv)
{
  int n;
  n = stoi(argv[1]);
  int n1 = n / 10000;
  long double tavg = (long double)0;
  long double *result = (long double *)malloc(n1 * sizeof(long double));
  Timer t;
  {
    ThreadPool pool(4);
    for (size_t c = 0; c < n1; c++)
      pool.enqueue([&result, n1, c]() { calc(n1, ref(result), c); });
  }
  for (int i = 0; i < n1; i++)
  {
    tavg += (long double)result[i];
  }
  tavg = (long double)tavg / n1;
  cout << t.elapsed() << "\t" << tavg << endl;

  return 0;
}