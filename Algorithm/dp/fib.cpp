#include <iostream>
#include <vector>
int fib(int N)
{
  if (N < 1)
    return 0;
  std::vector<int> memo(N, 0);
  return helper(memo, N);
}
int helper(std::vector<int> &memo, int n)
{
  if (n == 1 || n == 2)
  {
    return 1;
  }
  if (memo[n] != 0)
    return memo[n];
  memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
  return memo[n];
}