#include "D:\homework\git\CodeC\programTest1\include\queue.h"
#include <stdio.h>
#include <stdlib.h>

bool visit(QElemType c) {
  printf("%d ", c);
  return true;
}

bool initQueue(SqQueue* Q) {
  Q->rear = 0;
  Q->front = 0;
  return true;
}

bool clearQueue(SqQueue* Q) {
  Q->rear = 0;
  Q->front = 0;
  return true;
}

bool isEmptyQueue(SqQueue* Q) {
  return (Q->rear == Q->front);
}

bool isFullQueue(SqQueue* Q) {
  return ((Q->rear + 1) % MAXSIZE == Q->front);
}

int queueLength(SqQueue* Q) {
  return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

bool getHead(SqQueue* Q, QElemType* e) {
  if (isEmptyQueue(Q)) {
    return false;
  }
  *e = Q->data[Q->front];
  return true;
}

bool enQueue(SqQueue* Q, QElemType e) {
  if (isFullQueue(Q))
    return false;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return true;
}

bool deQueue(SqQueue* Q, QElemType* e) {
  if (isEmptyQueue(Q))
    return false;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return true;
}

bool traverseQueue(SqQueue* Q) {
  int i = Q->front;
  while (i != Q->rear) {
    visit(Q->data[i]);
    i = (i + 1) % MAXSIZE;
  }
  return true;
}