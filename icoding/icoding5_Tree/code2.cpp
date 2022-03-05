#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 50
typedef BiTNode *ElemType;
typedef struct
{
  ElemType elem[Stack_Size];
  int top;
} Stack;
void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  // x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false
typedef int DataType;
typedef struct Node
{
  DataType data;
  struct Node *left;
  struct Node *right;
} BiTNode, *BiTree;
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
  BiTree T = root, p = NULL;
  if (T == NULL || node == NULL || !is_empty(s))
    return false;
  while (T || !is_empty(s))
  {
    while (T)
    {
      push(s, T);
      if (T == node)
        return true;
      T = T->left;
    }
    top(s, &T);
    if (!T->right || T->right == p)
    {
      p = T;
      pop(s, &T);
      T = NULL;
    }
    else
      T = T->right;
  }
  return false;
}

bool path_my(BiTNode *root, BiTNode *node, Stack *s)
{
  BiTree T = root;
  while (!is_empty(s) || T)
  {
    if (T == node)
      return true;
    while (T)
    {
      push(s, T);
      if (T == node)
        return true;
      T = T->left;
      if (T == node)
        return true;
    }
    pop(s, &T);
    T = T->right;
    if (T == node)
      return true;
  }
  return false;
}