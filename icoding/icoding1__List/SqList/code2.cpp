#include "SqList.h"
/*编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。)*/
void del_dupnum(SeqList *L)
{
  int i, j;
  j = 0;
  for (i = 0; i <= L->last; ++i)
  {
    if (L->elem[i] != L->elem[i + 1])
    {
      L->elem[j] = L->elem[i];
      j++;
    }
  }
  L->last = j - 1;
}

int main()
{
  SeqList h;
  InitSqList(&h);
  PrintArray(h);
  printf("\n");
  del_dupnum(&h);
  PrintArray(h);
  return 0;
}