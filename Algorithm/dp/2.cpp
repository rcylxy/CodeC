#include <stdio.h>
int max(int a, int b)
{
  return a > b ? a : b;
}
void getArray(int *a, int n, int *dp)
{
  dp[0] = a[0] + 0;
  dp[1] = max(dp[0], a[1] + 1);
  for (int i = 2; i < n; ++i)
  {
    dp[i] = max(dp[i - 1], a[i] + i);
  }
  return;
}
int maxScoreSightseeingPair(int *values, int valuesSize)
{
  int dp[50005] = {0};
  int ret = 0;
  getArray(values, valuesSize, dp);
  for (int j = 1; j < valuesSize; ++j)
  {
    int temp = values[j] - j + dp[j - 1];
    if (temp > ret)
      ret = temp;
  }
  return ret;
}
int main()
{
  int values[] = {8, 1, 5, 2, 6}; // 0 1 2 3 4
  int valueSize = sizeof(values) / sizeof(values[0]);
  printf("%d", maxScoreSightseeingPair(values, valueSize));
}
