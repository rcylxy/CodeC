#include <stdio.h>
#include <stdlib.h>
int getSumOfArray(int n)
{
  int ret = 0;
  for (int i = 1; i < n; ++i)
  {
    if (n % i == 0)
    {
      ret += i;
    }
  }
  return ret;
}
void printNumbers(int N)
{
  for (int i = 2; i < N; ++i)
  {
    if (getSumOfArray(i) == i)
      printf("%d ", i);
  }
}
int main()
{
  printNumbers(1000);
}