#include "linklist.h"
/*已知线性表中的元素以值递增有序排列，并以单链表作存储结构。*/
/*试写一高效算法，删除表中所有大于mink且小于maxk的元素*/
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
  Node *p, *q;
  Node *mustBeRemain;
  p = L->next;
  while (p->data <= mink)
  {
    mustBeRemain = p; //此时mustberemain就指向了最后一个元素，需要被链接。
    p = p->next;
  }
  q = p->next;
  while (q->data < maxk)
  {
    free(p);
    p = q;
    q = q->next;
  }
  mustBeRemain->next = q;
}
int main()
{
  _lnklist L;
  InitLinkList(&L);
  CreateLinkList(&L);
  PrintLinkList(&L);
  lnk_del_x2y(&L, 1, 4);
  printf("\n");
  PrintLinkList(&L);
}