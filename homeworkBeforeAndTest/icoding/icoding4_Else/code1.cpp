/*实现三元组表示的两个稀疏矩阵的加法。相关定义如下：*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100 //假设非零元个数的最大值为100
#define ElemType int
typedef struct
{
  int i, j;   //非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
  ElemType e; //非零元的值
} Triple;

typedef struct
{
  Triple data[MAXSIZE]; // 非零元三元组表
  int m, n, len;        // 矩阵的行数、列数和非零元个数，并且len-1是最大的下标。
} TSMatrix;
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
  int iM, iN;
  int jM, jN;
  int M, N, Q;
  if ((*pM).m != (*pN).m || (*pM).n != (*pN).n)
    return false;
  pQ->m = pM->m;
  pQ->n = pM->n;
  for (M = 0, N = 0, Q = 0; M < pM->len && N < pN->len;)
  {
    iM = pM->data[M].i;
    iN = pN->data[N].i;
    jM = pM->data[M].j;
    jN = pN->data[N].j;
    if (iM > iN)
    {
      pQ->data[Q].e = pN->data[N].e;
      pQ->data[Q].i = pN->data[N].i;
      pQ->data[Q].j = pN->data[N].j;
      N++;
      Q++;
    }
    else if (iM < iN)
    {
      pQ->data[Q].e = pM->data[M].e;
      pQ->data[Q].i = pM->data[M].i;
      pQ->data[Q].j = pM->data[M].j;
      M++;
      Q++;
    }
    else if (iM == iN)
    {
      if (jM == jN)
      {
        if (pN->data[N].e + pM->data[M].e != 0)
        {
          pQ->data[Q].i = pM->data[M].i;
          pQ->data[Q].j = pM->data[M].j;
          pQ->data[Q].e = pN->data[N].e + pM->data[M].e;
          Q++;
        }
        M++;
        N++;
      }
      else if (jM < jN)
      {
        pQ->data[Q].e = pM->data[M].e;
        pQ->data[Q].i = pM->data[M].i;
        pQ->data[Q].j = pM->data[M].j;
        M++;
        Q++;
      }
      else if (jM > jN)
      {
        pQ->data[Q].e = pN->data[N].e;
        pQ->data[Q].i = pN->data[N].i;
        pQ->data[Q].j = pN->data[N].j;
        N++;
        Q++;
      }
    }
  }
  while (M < pM->len)
  {
    pQ->data[Q].e = pM->data[M].e;
    pQ->data[Q].i = pM->data[M].i;
    pQ->data[Q].j = pM->data[M].j;
    M++;
    Q++;
  }
  while (N < pN->len)
  {
    pQ->data[Q].e = pN->data[N].e;
    pQ->data[Q].i = pN->data[N].i;
    pQ->data[Q].j = pN->data[N].j;
    N++;
    Q++;
  }
  pQ->len = Q + 1;
  return true;
}