#include <stdio.h>
int main()
{
  int cnt = 0;
  for (int i = 1; i <= 5; ++i)
  {
    for (int j = 1; j <= 5; ++j)
    {
      for (int k = 1; k <= 5; ++k)
      {
        for (int l = 1; l <= 5; ++l)
        {
          for (int m = 1; m <= 5; ++m)
          {
            if (k != l && k != m && l != m && i != j && i != k && i != l && i != m && j != k && j != l && j != m)

              if (i != 1 && j != 2 && k != 3 && l != 4 && m != 5)
              {
                printf("(%d,%d,%d,%d,%d)\n", i, j, k, l, m);
                cnt++;
              }
          }
        }
      }
    }
  }
  printf("cnt==%d", cnt);
  return 0;
}