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
int init_cross_list(PCrossList M, const ElemType *A, int m, int n)
{
  OLNode *p, *q;
  int cnt = 0;
  M->rows = m;
  M->cols = n;
  M->nums = 0;
  if (!(M->rowhead = (OLink *)malloc(sizeof(OLink) * (m + 1))))
    return 0;
  if (!(M->colhead = (OLink *)malloc(sizeof(OLink) * (n + 1))))
    return 0;
  for (int i = 0; i <= m; ++i)
    M->rowhead[i] = NULL;
  for (int j = 0; j <= n; ++j)
    M->colhead[j] = NULL;
  for (cnt = 0; cnt < m * n; ++cnt) /* cnt-> cnt/n,cnt%n */
  {
    if (A[cnt] == 0)
      ;
    else
    {
      if (!(p = (OLNode *)malloc(sizeof(OLNode))))
        return 0;
      ;
      p->row = cnt / n + 1;
      p->col = cnt % n + 1;
      p->value = A[cnt];
      p->down = NULL;
      p->right = NULL;
      M->nums++;
      if (M->rowhead[p->row] == NULL)
        M->rowhead[p->row] = p;
      else
      {
        q = M->rowhead[p->row];
        while (q->right != NULL)
          q = q->right;
        q->right = p;
      }
      if (M->colhead[p->col] == NULL)
        M->colhead[p->col] = p;
      else
      {
        q = M->colhead[p->col];
        while (q->down != NULL)
          q = q->down;
        q->down = p;
      }
    }
  }
  return M->nums;
}

int del_cross_list(PCrossList L, ElemType k)
{
  OLNode *p, *q;
  int ret = 0;
  for (int cnti = 1; cnti <= L->rows; ++cnti)
  {
    p = L->rowhead[cnti];
    if (!p)
      continue;
    q = p;
    while (q)
    {
      if (L->rowhead[cnti]->value == k)
      {
        L->rowhead[cnti] = p->right;
        ret++;
        p = L->rowhead[cnti];
        q = p;
        continue;
      }
      if (q->value != k)
      {
        p = q;
        q = q->right;
      }
      else if (q->value == k)
      {
        p->right = q->right;
        q = p->right;
        ret++;
      }
    }
  }
  for (int cntj = 1; cntj <= L->cols; ++cntj)
  {
    p = L->colhead[cntj];
    if (!p)
      continue;
    while (L->colhead[cntj]->value == k)
    {
      q = L->colhead[cntj]->down;
      free(p);
      L->colhead[cntj] = q;
      p = q;
    }
    p = L->colhead[cntj];
    q = p->down;
    while (q)
    {
      if (q->value == k)
      {
        OLink tmp = p->down;
        p->down = q->down;
        p = p->down;
        free(tmp);
        continue;
      }
      else if (q->value != k)
      {
        p = q;
        q = q->down;
      }
    }
    return ret;
  }