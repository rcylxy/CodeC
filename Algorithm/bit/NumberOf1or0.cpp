#define N 100
#include <stdio.h>
#include <stdlib.h>
void printNumOf2Enter(int n)
{
  char ch[100] = "";
  int cnt = 0;
  while (n != 0)
  {
    ch[cnt] = n % 2 + '0';
    n /= 2;
    cnt++;
  }
  for (int i = cnt; i >= 0; --i)
  {
    printf("%c", ch[i]);
  }
}
int getNumOf2Enter(int n)
{
  int cnt = 0;
  while (n != 0)
  {
    n /= 2;
    cnt++;
  }
  return cnt;
}
int getNumberOf1(int n)
{
  int ret = 0;
  while (n != 0)
  {
    n &= n - 1;
    ret++;
  }
  return ret;
}
int getNumberOf0(int n)
{
  return getNumOf2Enter(n) - getNumberOf1(n);
}
int main()
{
  printNumOf2Enter(N);
  printf("\n%d", getNumOf2Enter(N));
  printf("\n%d", getNumberOf1(N));
  printf("\n%d", getNumberOf0(N));
}