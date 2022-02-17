#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef int ElemType;
struct _seqlist
{
  ElemType elem[MAXSIZE];
  int last;
};
typedef struct _seqlist SeqList;

#include <time.h>
void InitSqList(SeqList *L)
{
  srand((time(0)));
  for (int i = 0; i < MAXSIZE; ++i)
  {
    L->elem[i] = rand() % 50;
  }
  L->last = MAXSIZE - 1; //最后一个元素的下标
}
void PrintArray(SeqList L)
{
  printf("\n");
  for (int i = 0; i <= L.last; ++i)
  {
    printf("%d ", L.elem[i]);
  }
  printf("\n");
}