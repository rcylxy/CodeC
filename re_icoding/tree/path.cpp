#include "tree.h"
bool path(BiTNode *root, BiTNode *node, Stack *s);
int main()
{
  Stack s;
  init_stack(&s);
  s.top = -1;
  BiTree T;
  InitBiTree(&T);
  CreateBiTree(&T);
  BiTree node = T->left->right;
  path(T, node, &s);
}
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
  BiTree temp;
  BiTree px;
  s->top = -1;
  init_stack(s);
  push(s, root);
  while (!is_empty(s))
  {
  }
  return false;
}
/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
}