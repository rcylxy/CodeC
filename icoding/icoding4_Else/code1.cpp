/*实现三元组表示的两个稀疏矩阵的加法。相关定义如下：*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  if ((*pM).m != (*pN).m || (*pM).n != (*pN).n)
    return false;
}