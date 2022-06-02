#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _otherInfo
{
  int i;
  int j;
} OtherInfo;

typedef struct _minHeapNode
{
  int value;
  OtherInfo otherInfo;
} MinHeapNode, *PMinHeapNode;

typedef struct _minPQ
{
  PMinHeapNode heap_array; // 指向堆元素数组
  int heap_size;           // 当前堆中的元素个数
  int capacity;            //堆数组的大小
} MinHeap, *PMinHeap;
int parent(int i)
{
  return (i - 1) / 2;
}

int left(int i)
{
  return 2 * i + 1;
}

int right(int i)
{
  return 2 * i + 2;
}

void swap_node(MinHeapNode *x, MinHeapNode *y)
{
  int value = y->value;
  int i = y->otherInfo.i;
  int j = y->otherInfo.j;

  y->value = x->value;
  y->otherInfo.i = x->otherInfo.i;
  y->otherInfo.j = x->otherInfo.j;

  x->value = value;
  x->otherInfo.i = i;
  x->otherInfo.j = j;

  return;
}

bool heap_insert_value(PMinHeap pq, int value)
{
  if (pq->heap_size + 1 > pq->capacity)
  {
    return false;
  }
  int i = pq->heap_size;
  int j = parent(i);
  pq->heap_array[i].value = value;
  while (i)
  {
    if (value < pq->heap_array[j].value)
    {
      swap_node(&(pq->heap_array[i]), &(pq->heap_array[j]));
      i = j;
      j = parent(i);
    }
    else
    {
      pq->heap_size++;
      return true;
    }
  }
}
bool heap_insert_value(PMinHeap pq, int value)
{
  int i, j;
  i = pq->heap_size;
  j = parent(i);
  pq->heap_array[i].value = value;
  while (i)
  {
    if (value < pq->heap_array[j].value)
    {
      swap_node(&(pq->heap_array[i]), &(pq->heap_array[j]));
      i = j;
      j = parent(i);
    }
    else
    {
      pq->heap_size++;
      return true;
    }
  }
}