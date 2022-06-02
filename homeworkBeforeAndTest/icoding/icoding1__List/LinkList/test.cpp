#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#define val data
#define ListNode _lnklist
LinkList removeElements(LinkList head, ElemType val)
{
  struct ListNode *temp;
  if (head == NULL)
    return head;
  while (head && head->val == val)
  {
    temp = head->next;
    free(head);
    head = temp;
  }
  if (!head)
    return NULL;
  struct ListNode *p = head;
  struct ListNode *q = p->next;
  while (q)
  {
    if (q->val == val)
    {
      p->next = q->next;
      free(q);
    }
    q = p->next;
  }
  return head;
}
int main()
{
  _lnklist L;
  InitLinkList(&L);
  CreateLinkList(&L);
  PrintLinkList(&L);
  removeElements(&L, 2);
  printf("\n");
  PrintLinkList(&L);
  //[1 2 6 3 4 5 6]
}