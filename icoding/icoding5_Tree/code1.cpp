/* 先序遍历二叉树的非递归算法 */
#define Stack_Size 50
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
  ElemType elem[Stack_Size];
  int top;
} Stack;
typedef int DataType;
typedef struct Node
{
  DataType data;
  struct Node *left;
  struct Node *right;
} BiTNode, *BiTree;
typedef BiTNode *ElemType;
void visit_node(BiTNode *node);
void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  // x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false
void pre_order_not(BiTree root)
{
  if (root == NULL)
    return;
  printf("%d", root->data);
  pre_order_not(root->left);
  pre_order_not(root->right);
}
void pre_order_my(BiTree root)
{
  Stack *S;
  init_stack(S);
  ElemType px = root;
  while (px || !is_empty(S))
  {
    if (px->right)
      push(S, px->right);
    if (px->left)
    {
      visit_node(px);
      px = px->left;
    }
    if (px->left == NULL)
    {
      if (!is_empty(S))
      {
        pop(S, &px);
        visit_node(px);
      }
      else if (is_empty(S))
        return;
    }
  }
  return;
}
void pre_order_his(BiTree root)
{
  Stack *S;
  init_stack(S);
  ElemType T = root;
  while (T || !is_empty(S))
  {
    while (T)
    {
      visit_node(T);
      push(S, T);
      T = T->left;
    }
    pop(S, &T);
    T = T->right;
  }
}