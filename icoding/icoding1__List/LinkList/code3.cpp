#include "linklist.h"

void lnk_merge(LinkList A, LinkList B, LinkList C)
{
  Node *a, *b, *c;
  a = A->next;
  b = B->next;
  c = C;
  while (a && b)
  {
    c->next = a;
    a = a->next;
    c = c->next;
    c->next = b;
    b = b->next;
    c = c->next;
  }
  if ((!a) && (!b))
  {
    return;
  }
  else if (!a)
  {
    c->next = b;
    return;
  }
  else if (!b)
  {
    c->next = a;
    return;
  }
}

int main(int argc, char *argv[])
{
  _lnklist A;
  Init(&A);
  _lnklist B;
  Init(&B);
  _lnklist C;
  InitLinkList(&C);
  lnk_merge(&A, &B, &C);
}