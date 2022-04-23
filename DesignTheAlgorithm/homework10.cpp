#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define N 10
int main()
{
  int i;
  bool *pos = (bool *)malloc(sizeof(bool));
  for (int i = 0; i < N; ++i)
  {
    pos[i] = 0;
  }
  int a = 0;
  for (i = 0; i < MAX; i++)
  {
    pos[a] = true;
    a++;
    a += i;
    a = a % 10;
  }
  for (i = 0; i < N; i++)
    if (!pos[i])
      printf("兔子可能在第%d洞中\n", i + 1);
  return 0;
}