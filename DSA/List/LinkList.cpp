#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef enum
{
  OK,
  ERROR
} Status;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prior;
} Node, *Linklist;
void CreateListHead(struct Node **L, int n);
void CreateListTail(struct Node **L, int n);
Status GetElem(struct Node *L, int i, int *e);
Status ListInsertFront(struct Node **L, int i, int e);
Status ListInsertBehind(struct Node **L, int i, int e);
Status ListDelete(struct Node **L, int i);
void ClearList(struct Node **L);
void printlist(struct Node *L);

void CreateListHead(struct Node **L, int n)
{
  int input;
  (*L) = (struct Node *)malloc(sizeof(Node));
  (*L)->next = NULL;
  struct Node *s;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &input);
    s = (struct Node *)malloc(sizeof(Node));
    s->data = input;
    s->next = (*L)->next;
    (*L)->next = s;
    s->prior = (*L);
    //		(*L)->prior=
  }
  return;
}
void CreateListTail(struct Node **L, int n)
{
  int input;
  (*L) = (struct Node *)malloc(sizeof(Node));
  (*L)->next = NULL;
  struct Node *p = (*L);
  struct Node *s;
  for (int i = 0; i < n; ++i)
  {
    //		struct Node* r = p->next;
    scanf("%d", &input);
    s = (struct Node *)malloc(sizeof(Node));
    s->data = input;
    s->next = p->next;
    p->next = s;
    s->prior = p;
    p = p->next;
    (*L)->prior = s;
    s->next = (*L);
  }
}
Status GetElem(struct Node *L, int i, int *e) //寻找第i个结点的位置
{
  int j = 1;
  struct Node *p = L->next;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  else
    *e = p->data;
}
Status ListInsertFront(struct Node **L, int i, int e)
{
  struct Node *p = (*L);
  struct Node *s;
  int j = 1;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  s = (struct Node *)malloc(sizeof(Node));
  s->data = e;
  s->prior = p;
  s->next = p->next;
  p->next->prior = s;
  p->next = s;
  return OK;
}
Status ListInsertBehind(struct Node **L, int i, int e)
{
  struct Node *p = (*L)->next;
  struct Node *s;
  int j = 1;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  s = (struct Node *)malloc(sizeof(Node));
  s->data = e;
  if (p->next)
  {
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
  }
  else if (p->next == NULL)
  {
    s->prior = p;
    s->next = (*L);
    p->next = s;
    return OK;
  }
}
int main()
{
  struct Node *L;
  int n;
  int input1;
  printf("请输入初始化链表的长度：\n");
  scanf("%d", &n);
  CreateListTail(&L, n);

  printf("输入要查询的结点的位置：\n");
  scanf("%d", &input1);
  int e1;
  GetElem(L, input1, &e1);
  printf("该位置的元素是%d\n", e1);

  printf("输入要插入的结点的位置：\n");
  int e2;
  int input2;
  scanf("%d", &input2);
  printf("元素\n");
  scanf("%d", &e2);
  ListInsertBehind(&L, input2, e2);

  printf("输入要删除的结点的位置：\n");
  int input3;
  scanf("%d", &input3);
  ListDelete(&L, input3);
  printlist(L);
}