#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
struct _lnklist
{
  ElemType data;
  struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
void initLinkList(LinkList l)
{
  l = (LinkList)malloc(sizeof(struct _lnklist));
  l->data = 0;
  l->next = NULL;
}
void createNewLinkList(LinkList l)
{
  printf("请输入您要求的元素个数！\n");
  int len = 0;
  int data;
  LinkList p = l;
  LinkList q;
  scanf("%d", &len);
  if (len == 1)
  {
    scanf("%d", &data);
    l->data = data;
    return;
  }
  else
  {
    for (int i = 1; i <= len; ++i)
    {

      if (i == 1)
      {
        scanf("%d", &data);
        p->data = data;
      }
      else
      {
        scanf("%d", &data);
        q = (LinkList)malloc(sizeof(struct _lnklist));
        q->data = data;
        q->next = NULL;
        p->next = q;
        p = q;
      }
    }
  }
  p->next = NULL;
  return;
}
void printLinkList(LinkList l)
{
  while (l != NULL)
  {
    printf("%d ", l->data);
    l = l->next;
  }
  return;
}
LinkList removeNthFromEnd(LinkList head, int n)
{
  int cnt = 0;
  LinkList q = head;
  while (q != NULL)
  {
    cnt++;
    q = q->next;
  }
  if (cnt == n)
  {
    q = head;
    head = head->next;
    free(q);
    return head;
  }
  q = head; //寻找n-cnt+1个，从1开始
  for (int i = 1; i < cnt - n; ++i)
  {
    q = q->next;
  }
  printf("\n%d\n", q->data);
  LinkList p = q->next;
  q->next = p->next;
  free(p);
  return head;
}
int main()
{
  Node l;
  initLinkList(&l);
  createNewLinkList(&l);
  printLinkList(&l);
  removeNthFromEnd(&l, 7);
  printLinkList(&l);
  return 0;
}