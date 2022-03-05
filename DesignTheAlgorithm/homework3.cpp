#define N 30000
#include <stdio.h>
int main()
{
  int i, j;
  int sum = 0;
  long int s[N];
  for (i = 2; i < N; i++)
  {
    for (j = 1, s[i] = 0; j < i; j++)
    {
      if (i % j == 0)
      {
        s[i] += j;
      }
    }
  }
  for (i = 2; i < N; i++)
  {
    j = s[i];
    if (j > N)
      continue;
    if (i == s[j] && j > i)
    {
      printf("(%d,%d)\n", i, j);
      sum++;
    }
  }
  printf("%d", sum);
}