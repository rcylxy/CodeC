#include <stdio.h>
#include <stdlib.h>
void PrintArray(int a[], int len);
void DirectInsertSort(int b[], int len);
void DirectInsertSortWithSentry(int b[], int lenWithSentry);
void HalfInsertSortWithSentry(int b[], int lenWithSentry);
void ShellInsert(int b[], int dk);
void ShellSort(int b[], int dlta[], int t);
void BubbleSort(int b[], int len);
void QuickSort(int b[], int left, int right);
void SimpleSelectionSort(int b[], int len);

int a[] = {0, 5, 4, 3, 2, 1, 7, 6, 4, 11};
int len = sizeof(a) / sizeof(a[0]);
int lenWithSentry = len - 1;
int dlta[] = {5, 3, 1};
int lenOfDlta = sizeof(dlta) / sizeof(dlta[0]);

int main()
{
  PrintArray(a, len);
  // DirectInsertSort(a, len);
  // DirectInsertSortWithSentry(a, lenWithSentry);
  // HalfInsertSortWithSentry(a, lenWithSentry);
  // ShellSort(a, dlta, lenOfDlta);
  // BubbleSort(a, len);
  // QuickSort(a, 0, len - 1);
  // SimpleSelectionSort(a, len);
  PrintArray(a, len);
}
void PrintArray(int a[], int len)
{
  //  printf("\n");
  for (int i = 0; i < len; ++i)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}
void DirectInsertSort(int b[], int len)
{
  int i, j, x;
  for (i = 1; i < len; ++i)
  {
    x = b[i];
    for (j = i - 1; j >= 0 && b[j] > x; --j)
      b[j + 1] = b[j];
    b[j + 1] = x;
  }
}
void DirectInsertSortWithSentry(int b[], int lenWithSentry)
{
  int i, j;
  for (i = 2; i < lenWithSentry; ++i)
  {
    b[0] = b[i];
    if (b[i] > b[i - 1])
      ;
    else
    {
      for (j = i - 1; b[j] > b[0]; --j)
      {
        b[j + 1] = b[j];
      }
      b[j + 1] = b[0];
    }
  }
}
void HalfInsertSortWithSentry(int b[], int lenWithSentry)
{
  int i, j;
  for (i = 2; i <= lenWithSentry; ++i)
  {
    b[0] = b[i];
    int low = 1;
    int high = i - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (b[mid] > b[0])
      {
        high = mid - 1; //程序在执行完这一步以后退出，a[high+1]=a[mid]>a[0];
      }
      else
      {
        low = mid + 1;
      }
    }
    for (j = i - 1; j >= high + 1; --j)
    {
      b[j + 1] = b[j];
    }
    b[high + 1] = b[0];
  }
}
void ShellInsert(int b[], int dk)
{
  int i;
  int j;
  for (i = dk + 1; i <= lenWithSentry; ++i)
  {
    if (b[i] < b[i - dk])
    {
      b[0] = b[i];
      for (j = i - dk; j > 0 && b[0] < b[j]; j -= dk)
        b[j + dk] = b[j];
      b[j + dk] = b[0];
    }
  }
}
void ShellSort(int b[], int dlta[], int t)
{ // dlta数组不能有公因子
  int k;
  for (k = 0; k < t; k++)
  {
    ShellInsert(b, dlta[k]);
  }
}
void BubbleSort(int b[], int len)
{
  int flag = 1;
  int tmp;
  int m = len - 2;                          //趟数，n个数据需要n-1趟。此时是从第0趟到第n-2趟，共n-1趟。
  for (int i = 0; i <= m && flag == 1; ++i) // i是趟数
  {
    flag = 0;
    for (int j = 0; j <= m - i; ++j) // len个记录
    {                                // j+i=m;
      if (b[j] > b[j + 1])
      {
        tmp = b[j + 1];
        b[j + 1] = b[j];
        b[j] = tmp;
        flag = 1;
      }
    }
  }
}
void QuickSort(int b[], int left, int right)
{
  int i = left, j = right;
  int h;
  if (left > right)
    return;
  int temp = b[left];
  while (i != j)
  {
    while (b[j] >= temp && i < j)
      j--;
    while (b[i] <= temp && i < j)
      i++;
    if (i < j)
    {
      h = b[i];
      b[i] = b[j];
      b[j] = h;
    }
  }
  b[left] = b[i];
  b[i] = temp;
  QuickSort(b, left, i - 1);
  QuickSort(b, i + 1, right);
  return;
}
void SimpleSelectionSort(int b[], int len)
{
  int temp;
  for (int i = 0; i < len - 1; ++i)
  {
    int k = i;
    for (int j = i + 1; j < len; ++j)
    {
      if (b[j] < b[k])
        k = j;
    }
    if (k != i)
    {
      temp = b[i];
      b[i] = b[k];
      b[k] = temp;
    }
  }
}
