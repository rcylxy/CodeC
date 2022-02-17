#define MAX_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status
{
  ERROR,
  OK
};
typedef int QElemType;
typedef struct Queue
{
  QElemType data[MAX_SIZE];
  int rear;  //tail
  int front; //head
} SqQueue;
Status visit(QElemType c);
Status InitQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
bool QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q, QElemType *e);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);
Status QueueTraverse(SqQueue Q);
int main(int argc, char *argv[])
{
}
Status visit(QElemType c)
{
  printf("%d ", c);
  return OK;
}
Status InitQueue(SqQueue *Q)
{
  Q->rear = 0;
  Q->front = 0;
  return OK;
}
Status ClearQueue(SqQueue *Q)
{
  Q->rear = 0;
  Q->front = 0;
  return OK;
}
bool QueueEmpty(SqQueue Q)
{
  if (Q.front == Q.rear)
    return true;
  else
    return false;
}
int QueueLength(SqQueue Q)
{
  return (Q.front - Q.rear + MAX_SIZE) % MAX_SIZE;
}
Status GetHead(SqQueue Q, QElemType *e)
{
  if (Q.rear == Q.front)
    return ERROR;
  *e = Q.data[Q.front];
  return OK;
}
Status EnQueue(SqQueue *Q, QElemType e)
{
  if ((Q->rear + 1) % MAX_SIZE == Q->front)
    return ERROR;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAX_SIZE;
  return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e)
{
  if (Q->rear == Q->front)
    return ERROR;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAX_SIZE;
}
Status QueueTraverse(SqQueue Q)
{
  if (Q.front == Q.rear)
    return ERROR;
  int tmp = Q.data[Q.front];
  int i = 0;
  while (i != Q.rear)
  {

    int i;
    i = Q.front;
    while (i != Q.rear)
    {
      visit(Q.data[i]);
      i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
    return OK;
  }
}