#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
int parent(int i);                              //返回堆元素数组下标为 i 的结点的父结点下标
int left(int i);                                //返回堆元素数组下标为 i 的结点的左子结点下标
int right(int i);                               //返回堆元素数组下标为 i 的结点的右子结点下标
void swap_node(MinHeapNode *x, MinHeapNode *y); //交换两个堆元素的值