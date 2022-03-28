/*实现三元组表示的两个稀疏矩阵的加法。相关定义如下：

#define MAXSIZE 100          //假设非零元个数的最大值为100
typedef struct {
    int i,j;									//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;						//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];			// 非零元三元组表
    int    m, n, len;							// 矩阵的行数、列数和非零元个数
}TSMatrix;
在三元组中，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
矩阵加法函数的原型为：

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ);
pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，函数返回 false，否则函数返回 true，且 pQ 指向两个矩阵的和。*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100 //假设非零元个数的最大值为100
#define ElemType int
#define MAXSIZE 100 //假设非零元个数的最大值为100
// success!!! 重写成功
typedef struct
{
  int i, j;   //非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
  ElemType e; //非零元的值
} Triple;

typedef struct
{
  Triple data[MAXSIZE]; // 非零元三元组表
  int m, n, len;        // 矩阵的行数、列数和非零元个数
} TSMatrix;
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
  if ((!pM) || (!pN) || (!pQ) || pM->m != pN->m || pM->n != pN->n)
    return false;
  pQ->m = pM->m;
  pQ->n = pM->n;
  int M = 0, N = 0, Q = 0, mi = 0, mj = 0, ni = 0, nj = 0;
  for (; M < pM->len && N < pN->len; ++M, ++N)
  {
    if (pM->data[M].i < pN->data[N].i)
    {
      pQ->data[Q].e = pM->data[M].e;
      pQ->data[Q].i = pM->data[M].i;
      pQ->data[Q].j = pM->data[M].j;
      pQ->len++;
      Q++;
    }
    else if (pM->data[M].i > pN->data[N].i)
    {
      pQ->data[Q].e = pN->data[N].e;
      pQ->data[Q].i = pN->data[N].i;
      pQ->data[Q].j = pN->data[N].j;
      pQ->len++;
      Q++;
    }
    else if (pM->data[M].i == pN->data[N].i)
    {
      if (pM->data[M].j > pN->data[N].j)
      {
        pQ->data[Q].e = pN->data[N].e;
        pQ->data[Q].i = pN->data[N].i;
        pQ->data[Q].j = pN->data[N].j;
        pQ->len++;
        Q++;
      }
      if (pM->data[M].j < pN->data[N].j)
      {
        pQ->data[Q].e = pM->data[M].e;
        pQ->data[Q].i = pM->data[M].i;
        pQ->data[Q].j = pM->data[M].j;
        pQ->len++;
        Q++;
      }
      if (pM->data[M].j == pN->data[N].j)
      {
        if (pM->data[M].e + pN->data[N].e != 0)
        {
          pQ->data[Q].e = pM->data[M].e;
          pQ->data[Q].i = pM->data[M].i;
          pQ->data[Q].j = pM->data[M].e + pN->data[N].e;
          pQ->len++;
          Q++;
        }
      }
    }
  }
  if (M == pM->m && N == pN->n)
    return true;
  while (M < pM->m)
  {
    pQ->data[Q].e = pM->data[M].e;
    pQ->data[Q].i = pM->data[M].i;
    pQ->data[Q].j = pM->data[M].j;
    pQ->len++;
    Q++;
    M++;
  }
  while (N < pN->n)
  {
    pQ->data[Q].e = pN->data[N].e;
    pQ->data[Q].i = pN->data[N].i;
    pQ->data[Q].j = pN->data[N].j;
    pQ->len++;
    Q++;
    N++;
  }
  return true;
}