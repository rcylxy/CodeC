#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};




struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  int temp;
  struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
  ret->next = NULL;
  struct ListNode *p;
  struct ListNode *q;
  p = ret;
  int flagOfret = 0;
  while (l1 && l2)
  {
    if (temp >= 10)
    {
      temp = 1;
    }
    else if (temp < 10)
    {
      temp = 0;
    }
    temp += l1->val;
    l1 = l1->next;
    temp += l2->val;
    l2 = l2->next;
    if (flagOfret == 0)
    {
      p = ret;
      p->val = temp % 10;
      p->next = NULL;
      flagOfret = 1;
    }
    else if (flagOfret == 1)
    {
      q = (struct ListNode *)malloc(sizeof(struct ListNode));
      q->val = temp % 10;
      q->next = NULL;
      p->next = q;
      p = q;
    }
  }
  while (l1 || l2)
  {
    if (temp < 10)
    {
      temp = 0;
    }
    else if (temp >= 10)
    {
      temp = 1;
    }
    if (l1 == NULL && l2 != NULL)
    {
      temp += l2->val;
      l2 = l2->next;
    }
    else if (l2 == NULL && l1 != NULL)
    {
      temp += l1->val;
      l1 = l1->next;
    }
    q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->val = temp % 10;
    q->next = NULL;
    p->next = q;
    p = q;
  }
  if (!l1 && !l2 && temp >= 10)
  {
    q = (struct ListNode *)malloc(sizeof(struct ListNode));
    flagOfret = 1;
    q->val = 1;
    q->next = NULL;
    p->next = q;
    p = q;
  }
  return ret;
}
/*struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  int cnt = 1;
  long sum = 0;
  //求出sum的值
  while (l1 != NULL || l2 != NULL)
  {
    if (l1 != NULL && l2 != NULL)
    {
      sum += l1->val * cnt;
      l1 = l1->next;
      sum += l2->val * cnt;
      l2 = l2->next;
    }
    else if (l1 == NULL && l2 != NULL)
    {
      sum += l2->val * cnt;
      l2 = l2->next;
    }
    else if (l2 == NULL && l1 != NULL)
    {
      sum += l1->val * cnt;
      l1 = l1->next;
    }
    cnt *= 10;
  }
  struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
  ret->next = NULL;
  ret->val = sum % 10;
  sum = sum / 10;
  struct ListNode *p;
  struct ListNode *q;
  p = ret;
  while (sum != 0)
  {
    q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->val = sum % 10;
    q->next = NULL;
    p->next = q;
    p = q;
    sum = sum / 10;
  }
  return ret;
}*/