#include <iostream>
#include <stdio.h>
#define N 10
#define MAX 1000
int main()
{
  bool hole[N + 1] = {0};
  int pos = 1;
  for (int i = 1; i < MAX; i++)
  {
    hole[pos] = true;
    pos += i + 1;
    pos = pos % 10;
  }
  for (int i = 1; i < N; i++)
    if (!hole[i])
      printf("兔子可能在第%d洞中\n", i);
}