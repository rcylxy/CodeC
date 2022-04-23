#include <stdio.h>
#include <stdlib.h>
int getSum(int n)
{
  int ret = 0;
  while (n != 0)
  {
    ret += (n % 10) * (n % 10);
    n = n / 10;
  }
  return ret;
}
bool isHappy(int n)
{
  
}
int main()
{
  printf("%d", getSum(100));
}