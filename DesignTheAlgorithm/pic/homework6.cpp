#define MAX_NAME 4
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main()
{
  srand((unsigned int)(time(0)));
  for (int i = 0; i < 10; ++i)
  {
    double a = (double)rand();
    for (int i = 1; i <= MAX_NAME; ++i)
    {
      printf("%.f", a / MAX_NAME);
      if (i != MAX_NAME)
      {
        printf("*");
      }
      if (i == MAX_NAME)
      {
        printf("=");
        printf("%.f", pow(a / MAX_NAME, MAX_NAME));
      }
    }
    printf("\n");
    Sleep(100);
  }
}