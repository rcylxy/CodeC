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
  BiTree node = T->right->left;
  pre_order(T);
  printf("\n");
  path(T, node, &s);

  TraverseStack(&s);
}
/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
  if (!root || !is_empty(s) || node == NULL)
    return false;
  BiTNode *T = root, *mark = NULL;
  while (T || !is_empty(s))
  {
    while (T)
    {
      push(s, T);
      if (T == node)
      {
        return true;
      }
      T = T->left;
    }
    top(s, &T);
    if (!T->left || T->right == mark)
    {
      mark = T;
      pop(s, &T);
      T = NULL;
    }
    else
      T = T->right;
  }
  return false;
}
/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/