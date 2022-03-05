#include <stdio.h>
int main()
{
  int cnt = 0;
  int sum = 0;
  int start = 1;
  while (start < 100)
  {
    sum += start;
    start++;
    if (sum % 9 == 0)
    {
      cnt++;
    }
  }
  printf("%d", cnt);
}