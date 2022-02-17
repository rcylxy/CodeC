#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef int ElemType;
typedef struct _QueueNode
{
  ElemType data;           /*数据域*/
  struct _QueueNode *next; /*指针域*/
} LinkQueueNode, *LinkQueue;
/*1: 队列初始化，成功返回真，否则返回假
2: 入队列，成功返回真，否则返回假：
3: 出队列，成功返回真，且*x为出队的值，否则返回假*/
bool init_queue(LinkQueue *LQ)
{
  *LQ = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
  if ((*LQ) == NULL)
    return false;
  (*LQ)->next = (*LQ);
  return true;
}
bool enter_queue(LinkQueue *LQ, ElemType x)
{
  LinkQueueNode *p;
  p = (LinkQueueNode *)malloc(sizeof(LinkQueue));
  if (!p)
    return false;
  p->data = x;
  p->next = (*LQ)->next;
  (*LQ)->next = p; //目的是将*LQ与p连接起来
  *LQ = p;         //*LQ是队尾指针，自然是指向了队尾。
  return true;
}
bool leave_queue(LinkQueue *LQ, ElemType *x)
{
  if ((*LQ) == (*LQ)->next)
    return false;
  LinkQueueNode *p = (*LQ)->next->next;
  *x = p->data;
  if ((*LQ)->next->next == (*LQ))
  {
    (*LQ) = (*LQ)->next;
    (*LQ)->next = (*LQ);
  }
  else
    (*LQ)->next->next = p->next;
  free(p);
  return true;
}

int main(int argc, char *argv[])
{
  LinkQueue LQ;
  init_queue(&LQ);
  int x;
  int cnt = 1;

  for (int i = 0; i < 10; i++)
  {
    enter_queue(&LQ, i);
    printf("%d添加成功\n", i);
  }
  for (int i = 0; i < 10; i++)
  {
    leave_queue(&LQ, &x);
    printf("%d删除成功\n", x);
  }
}