#include <stdio.h>
#include <stdlib.h>
int main()
{
  int prior;
  int parent;
  int i = 0, j = 0, k = 0, q = 0;
  prior = 1000 * i + 100 * j + 10 * k + q;
  for (i = 1; i < 10; ++i)
    for (j = 1; j < 10; ++j)
      for (k = 1; k < 10; ++k)
        for (q = 1; q < 10; ++q)
        {
          prior = 1000 * i + 100 * j + 10 * k + q;
          parent = 1000 * q + 100 * k + 10 * j + i;
          if (4 * prior == parent)
          {
            printf("homework1\n");
            printf("%d", prior);
            return 0;
          }
        }
}