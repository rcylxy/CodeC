#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 20
typedef int ElemType;
struct _lnklist
{
  ElemType data;
  struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
void InitLinkList(LinkList L)
{
  L = (LinkList)malloc(sizeof(Node));
  L->data = NULL;
  L->next = NULL;
  return;
}
void CreateLinkList(LinkList L)
{
  Node *p = L;
  Node *q = L->next;
  int num;
  int temp;
  printf("请您输入元素的个数:\n");
  scanf("%d", &num);
  for (int i = 1; i <= num; ++i)
  {
    q = (Node *)malloc(sizeof(Node));
    scanf("%d", &temp);
    q->data = temp;
    p->next = q;
    p = p->next;
  }
  p->next = NULL;
}
void PrintLinkList(LinkList L)
{
  Node *p = L->next;
  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}
void Init(LinkList L)
{
  InitLinkList(L);
  CreateLinkList(L);
  // PrintLinkList(L);
  printf("\n");
}
int Traverse(LinkList L)
{
  int cnt = 0;
  Node *p = L->next;
  while (p)
  {
    cnt++;
    p = p->next;
  }

  return cnt;
}
void EasyMergeLinkList(LinkList A, LinkList B, LinkList C)
{
  Node *a, *b, *c;
  a = A->next;
  b = B->next;
  c = C;
  while (a)
  {
    c->next = a;
    a = a->next;
    c = c->next;
  }
  c->next = b;
  return;
}