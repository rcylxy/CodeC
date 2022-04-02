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
  TraverseStack(&s);
}
/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
  BiTree temp;
  BiTree px;
  s->top = -1;
  init_stack(s);
  int flag = 1;
  push(s, root);

  while (!is_empty(s))
  {
    top(s, &temp);
    if (temp->right == px)
    {
      pop(s, &px);
    }
    if (flag == 1)
    {
      if (temp == node)
        return true;
    }
    if (temp->left && flag == 1)
    {
      push(s, temp->left);
    }
    else if (!temp->left || flag == 0)
    {
      flag = 0;
      if (temp->right)
      {
        push(s, temp->right);
        flag = 1;
      }
      if (flag == 0)
        pop(s, &px);
    }
  }
  return false;
}
/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/