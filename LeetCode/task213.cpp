#define SIZE 4
#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
  return a > b ? a : b;
}
void printArray(int **a)
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}
int **getChangeNum(int nums[SIZE])
{
  int **changeNums = (int **)malloc(sizeof(int *) * SIZE);
  for (int j = 0; j < SIZE; ++j)
  {
    changeNums[j] = (int *)malloc(sizeof(int) * SIZE);
  }

  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      changeNums[i][j] = nums[(i + j) % SIZE];
    }
  }
  //  printArray(changeNums);
  return changeNums;
}
int robToTemp(int *nums, int numsSize)
{
  int dp[105] = {0};
  dp[0] = nums[0];
  if (numsSize == 1)
    return dp[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < numsSize - 1; ++i)
  {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[numsSize - 2];
}
int rob(int *nums, int numsSize)
{
  int **work = (int **)malloc(sizeof(int *) * SIZE);
  for (int j = 0; j < SIZE; ++j)
  {
    work[j] = (int *)malloc(sizeof(int) * SIZE);
  }
  work = getChangeNum(nums);

  printArray(work);
  printf("\n");

  int maxToret = 0;
  for (int i = 0; i < SIZE; ++i)
  {
    int temp = robToTemp(work[i], SIZE);
    printf("%d ", temp);
    if (temp > maxToret)
      maxToret = temp;
  }
  return maxToret;
}

int main()
{
  int nums[SIZE] = {1, 2, 3, 4};
  printf("ret:   %d", rob(nums, SIZE));
}