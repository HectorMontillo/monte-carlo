#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  srand(time(NULL));
  int i;         //(counter)
  double l;      //(lenght of needle)
  double n;      //(number of trials)
  double L;      //(width between lines)
  double x;      //(angle)
  double pi;     //(pi)
  double P = 0;  //(ammount of trials that worked)
  double d;      //(distance between centre of needle and line)
  double y;      //minimalizacja obliczeń
  double stosun; // (cantidad de ensayos a cantidad de ensayos exitosos)

  /*printf("Program szacuje wartosc liczby pi metoda Monte Carlo na podstawie Igly Buffona. Prosze Pamietac o:\n-Podaniu liczby prób jako wartości większej od zera i całkowitej\n-Podaniu długości igły mniejszej niż szerokości między liniami\n");
  printf("Prosze podac liczbe prob:\n");
  scanf("%lf", &n);
  printf("Prosze podac dlugosc igly:\n");
  scanf("%lf", &l);
  printf("Prosze podac szerokość miedzy liniami:\n");
  scanf("%lf", &L);*/
  n = 10;
  l = 1;
  L = 2;
  if (n <= 0.0 || l > L)
  {
    printf("Nastąpił błąd wynikających z podania niepoprawnych danych\n");
    return 1;
  }
  printf("%f %f %f", n, l, L); //debuging midway

  for (i = 0; i < n; i++)
  {
    x = ((double)rand() / RAND_MAX) * 3.1415; // losowy kat w radianach (random angle in radians)

    d = ((double)rand() / RAND_MAX) * L / 2; // losowa dlugosc igly mniejsza niz odstep miedzy liniami (random needle lenght)

    y = (l / 2) * sin(x);
    printf("Próba%d\n", i);
    if (d <= y)
    {
      P++;
    }
  }

  stosun = n / P;
  printf("Stosun %lf", stosun);
  pi = stosun * 2 * l / L;
  printf("liczba pi=%lf", pi);
  return 0;
}