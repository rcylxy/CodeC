#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
  return (a > b ? a : b);
}
int maxInArray(int *a, int numsize)
{
  int max = a[0];
  int i = 0;
  while (i < numsize)
  {
    if (a[i] > max)
    {
      int t = max;
      max = a[i];
      a[i] = t;
    }
    i++;
  }
  return max;
}
int maxSubArray(int *nums, int numsSize)
{
  int dp[10001] = {0};
  dp[0] = nums[0];
  dp[1] = max(dp[0] + nums[1], nums[1]);
  for (int i = 2; i < numsSize; ++i)
  {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
  }
  return maxInArray(dp, numsSize);
}
int main(int argc, char *argv[])
{
  int num[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d", maxSubArray(num, 9));
}