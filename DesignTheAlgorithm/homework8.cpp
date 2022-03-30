#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//其实就是问7个之间插三个板有多少可能，一共6个空。即C63*A77
long int fact(int n)
{
  if (n == 1)
    return n;
  else if (n == 2)
    return n;
  else
    return n * fact(n - 1);
}
int main()
{
  int m = 6;
  int n = 3;
  int h = 7;
  std::cout << (fact(m) / (fact(m - n) * fact(n))) * fact(h);
}