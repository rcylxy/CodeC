#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;
// 非零元素结点结构
typedef struct OLNode
{
  int row, col;
  ElemType value;
  struct OLNode *right, *down;
} OLNode, *OLink;
// 十字链表结构
typedef struct
{
  OLink *rowhead, *colhead;
  int rows, cols, nums;
} CrossList, *PCrossList;
/*
2）实现十字链表的删除操作：
int del_cross_list(PCrossList L, ElemType k);
其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。
*/
int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
  OLNode *p, *q;
  int sum = 0;
  L->rows = m;
  L->cols = n;
  if (!((L->rowhead = (OLink *)malloc(sizeof(OLink) * (m + 1)))))
    exit(_OVERFLOW);
  if (!((L->colhead) = (OLink *)malloc(sizeof(OLink) * (n + 1))))
    exit(_OVERFLOW);
  int i, j;
  // init
  for (i = 0; i < m; ++i)
    L->rowhead[i] = NULL;
  for (j = 0; j < n; ++j)
    L->colhead[j] = NULL;
  // assign
  for (i = 0; i < m; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      if (A[n * i + j] != 0)
      {
        sum++;
        if (!(p = (OLNode *)malloc(sizeof(OLink))))
          return 0;
        p->col = n;
        p->row = m;
        p->value = A[n * i + j];
        if (L->rowhead[i] == NULL)
        {
          L->rowhead[i] = p;
        }
        else if (p->col < L->rowhead[i]->col)
        {
          p->right = L->rowhead[i];
          L->rowhead[i] = p;
        }
        else
        {
          for (q = L->rowhead[i]; q->right && q->right->col < j; q = q->right)
          {
            p->right = q->right;
            q->right = p;
          }
        }
        if (L->colhead[j] == NULL)
        {
          L->colhead[j] = p;
        }
        else if (p->row < L->colhead[j]->row)
        {
          p->down = L->colhead[j];
          L->colhead[j] = p;
        }
        else
        {
          for (q = L->colhead[j]; q->down && q->down->row < i; q = q->down)
          {
            p->down = q->down;
            q->down = p;
          }
        }
      }
    }
  }
  L->nums = sum;
  return sum;
}
int del_cross_list(PCrossList L, ElemType k)
{
  int sum = 0;
  OLNode *p, *q, *s;
  OLNode *x, *y, *z;
  for (int i = 0; i < L->rows; ++i)
  {
    p = L->rowhead[i];
    q = p;
    while (p)
    {
      if ((p->value == k) && (p == q))
      {
        L->rowhead[i] = L->rowhead[i]->right;
        free(p);
        p = L->rowhead[i];
        sum++;
      }
      else if (p->value == k)
      {
        q->right = p->right;
        free(p);
        p = q->right;
        sum++;
      }
      else
      {
        q = p;
        p = p->right; //保留前面那一个
      }
    }
  }
  L->nums -= sum;
  return sum;
}