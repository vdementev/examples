#include <stdio.h>
#include <stdlib.h>

// Recursive definition for equation from A
int g(int n)
{
  if (n > 100)
  {
    return n - 10;
  }
  else
  {
    return g(g(n + 11));
  }
}

// Recursive definition for equation from D
int ac(int m, int n)
{
  if (m == 0 && n >= 0)
  {
    return n + 1;
  }
  else if (m > 0 && n == 0)
  {
    return ac(m - 1, 1);
  }
  else if (m > 0 && n > 0)
  {
    return ac(m - 1, ac(m, n - 1));
  }
  else
  {
    printf("Oops\n");
    return 0;
  }
}

// Code for B and E
int main()
{
  int m = 0;
  int n = 0;
  // int max = 110;

  // for (n = 1; n <= max; n++)
  // {
  //   printf("g(%d)=%d\n", n, g(n));
  // }

  printf("\nTask D and C\n");

  m = 0;
  n = 0;
  printf("ac(%d,%d)=%d\n", m, n, ac(m, n));

  m = 1;
  n = 1;
  printf("ac(%d,%d)=%d\n", m, n, ac(m, n));

  m = 2;
  n = 2;
  printf("ac(%d,%d)=%d\n", m, n, ac(m, n));

  m = 3;
  n = 3;
  printf("ac(%d,%d)=%d\n", m, n, ac(m, n));

  printf("\nEND\n");
  return 0;
};