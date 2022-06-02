#include "linklist.h"
/*已知一个带有表头结点的单链表, 假设链表只给出了头指针L。*/
/*在不改变链表的前提下，请设计一个尽可能高效的算法*/
/*查找链表中倒数第k个位置上的结点（k为正整数）。*/
/*若查找成功，函数通过指针参数 p_ele 返回该结点 data 域的值，*/
/*此时函数返回 1；否则，函数返回 0。*/
int lnk_search(LinkList L, int k, ElemType *p_ele)
{
  Node *p = L->next;
  int array[MAXSIZE];
  int cnt = 0;
  while (p)
  {
    array[cnt] = p->data;
    p = p->next;
    ++cnt;
  }
  if (cnt + 1 < k)
    return 0;
  else
  {
    *p_ele = array[cnt - k];
    return 1;
  }
}
int main()
{
  int e;
  _lnklist L;
  InitLinkList(&L);
  CreateLinkList(&L);
  PrintLinkList(&L);
  printf("\n");
  printf("倒数第几个元素？");
  int h;
  scanf("%d", &h);
  printf("\n");
  if (lnk_search(&L, h, &e) != 0)
    printf("e的值是%d", e);
  else
    printf("不存在");
  printf("\n");
}