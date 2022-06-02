#include "SqList.h"
void del_x2y(SeqList *L, ElemType x, ElemType y)
{
  int cnt = 0;
  int j = 0, tmp = L->last;
  while (cnt <= tmp)
  {
    if ((L->elem[cnt] <= y) && (L->elem[cnt] >= x))
      ;
    else
    {
      L->elem[j] = L->elem[cnt];
      j++;
    }
    L->last = j - 1;
    cnt++;
  }
}