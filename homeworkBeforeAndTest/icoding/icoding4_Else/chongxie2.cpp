/*十字链表相关定义如下：

typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;
1）实现十字链表的初始化操作：

 int init_cross_list(PCrossList L, const ElemType *A, int m, int n);
其中 L 指向 CrossList 结构，且各成员已被初始化为0；
A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
m 表示十字链表的行数，n 表示十字链表的列数。
init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。

2）实现十字链表的删除操作：

 int del_cross_list(PCrossList L, ElemType k);
其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。*/
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
    while (p)
    {
      if (p == L->colhead[cntj] && L->colhead[cntj]->value == k)
      {
        q = L->colhead[cntj];
        L->colhead[cntj] = L->colhead[cntj]->down;
        p = L->colhead[cntj];
        free(q);
      }
      else if (p->value == k)
      {
        q->down = p->down;
        p = p->down;
        free(q->down);
      }
      else if (p->value != k)
      {
        q = p;
        p = q->down;
      }
    }
  }
  return ret;
}