#define MAX_SIZE 20
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QElemType;
enum Status
{
  OK,
  ERROR
};
typedef struct QNode
{
  QElemType data;
  struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
  QueuePtr front;
  QueuePtr rear;
} LinkQueue;
Status visit(QElemType c)
{
  printf("%d ", c);
  return OK;
}
Status InitQueue(LinkQueue *Q)
{
  Q->front = (QueuePtr)malloc(sizeof(QNode));
  if (Q->front == NULL)
  {
    return ERROR;
  }
  Q->rear = Q->front;
  Q->front->next = NULL;
  return OK;
}
Status DestroyQueue(LinkQueue *Q)
{
  while (Q->front)
  {
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return OK;
}
Status ClearQueue(LinkQueue *Q)
{
  QueuePtr p, q;
  Q->rear = Q->front;
  p = Q->front->next;
  while (p)
  {
    q = p;
    p = p->next;
    free(q);
  }
  return OK;
}
bool QueueEmpty(LinkQueue Q)
{
  if (Q.front == Q.rear)
    return true;
  return false;
}
int QueueLength(LinkQueue Q)
{
  int i = 0;
  QueuePtr p = Q.front;
  while (p != Q.rear)
  {
    i++;
    p = p->next;
  }
  return i;
}
Status GetHead(LinkQueue Q, QElemType *e)
{
  QueuePtr p;
  if (Q.front == Q.rear)
    return ERROR;
  p = Q.front->next;
  *e = p->data;
  return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  if (!p)
    return ERROR;
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
  return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e)
{
  QueuePtr p, q;
  if (Q->front == Q->rear)
    return ERROR;
  p = Q->front->next;
  *e = p->data;
  if (Q->rear == p)
    Q->rear = Q->front;
  Q->front->next = p->next;
  free(p);
  return OK;
}
Status QueueTraverse(LinkQueue Q)
{
  QueuePtr p;
  p = Q.front->next;
  while (p)
  {
    visit(p->data);
    p = p->next;
  }
  printf("\n");
  return OK;
}
int main()
{
}