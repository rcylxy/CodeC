#include "SqList.h"
/*已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分。
左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数
并要求算法的时间复杂度为O(n),空间复杂度为O（1）*/
void odd_even(SeqList *L)
{
  int i, j;
  j = 0;       //偶数
  i = L->last; //奇数
  while (i > j)
  {
    if (L->elem[i] % 2 == 0)
      i--; //偶数-1
    if (L->elem[j] % 2 != 0)
      j++; //奇数+1
    if (L->elem[i] % 2 != 0 && L->elem[j] % 2 == 0)
    {
      int tmp = L->elem[i];
      L->elem[i] = L->elem[j];
      L->elem[j] = tmp;
    }
  }
}
int main()
{
  SeqList h;
  InitSqList(&h);
  PrintArray(h);
  printf("\n");
  odd_even(&h);
  PrintArray(h);
  return 0;
}