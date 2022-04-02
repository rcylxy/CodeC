#include <Windows.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Stack_Size 50
typedef int DataType;
typedef struct Node
{
  DataType data;
  struct Node *left;
  struct Node *right;
} BiTNode, *BiTree;
typedef BiTNode *ElemType;
typedef struct
{
  BiTNode *elem[Stack_Size];
  int top;
} Stack;
void pre_order(BiTree root);
bool is_empty(Stack *S);
bool is_full(Stack *S);
void init_stack(Stack *S);
bool push(Stack *S, ElemType x);
bool pop(Stack *S, ElemType *px);
bool top(Stack *S, ElemType *px);
bool InitBiTree(BiTree *T);
bool CreateBiTree(BiTree *T);
void visit_node(BiTNode *node);
void TraverseStack(Stack *s);
bool is_empty(Stack *S)
{
  return (S->top == -1);
}
bool is_full(Stack *S)
{
  return (S->top == Stack_Size);
}
void init_stack(Stack *S)
{
  S = (Stack *)malloc(sizeof(Stack));
  S->top = -1;
  return;
}
bool push(Stack *S, ElemType x)
{
  if (is_full(S))
    return false;
  S->top++;
  S->elem[S->top] = x;
  return true;
}
bool pop(Stack *S, ElemType *px)
{
  if (is_empty(S))
    return false;
  *px = S->elem[S->top];
  S->top--;
  return true;
}
bool top(Stack *S, ElemType *px)
{
  if (is_full(S))
    return false;
  *px = S->elem[S->top];
  return true;
}
bool InitBiTree(BiTree *T)
{
  *T = NULL;
  return true;
}
bool CreateBiTree(BiTree *T)
{
  int el;
  scanf("%d", &el);
  if (el == -1)
  {
    //以-1作为虚节点的元素
    *T = NULL;
  }
  else
  {
    *T = (BiTree)malloc(sizeof(BiTNode));
    if (!*T)
      exit(-1);
    (*T)->data = el;
    CreateBiTree(&((*T)->left));
    CreateBiTree(&((*T)->right));
  }
  return true;
}
void visit_node(BiTNode *node)
{
  printf("%d ", node->data);
}
void TraverseTree(BiTree *T)
{
  if (*T == NULL)
    return;
  visit_node(*T);
  TraverseTree(&((*T)->left));
  TraverseTree(&((*T)->right));
  return;
}
void pre_order(BiTree root)
{
  BiTree temp;
  BiTree px;
  Stack s;
  s.top = -1;
  init_stack(&s);
  int flag = 1;
  push(&s, root);
  while (!is_empty(&s))
  {
    top(&s, &temp);
    if (flag == 1)
    {
      visit_node(temp);
    }
    if (temp->left && flag == 1)
    {
      push(&s, temp->left);
    }
    else if (!temp->left || flag == 0)
    {
      pop(&s, &px);
      flag = 0;
      if (temp->right)
      {
        push(&s, temp->right);
        flag = 1;
      }
    }
  }
}
void TraverseStack(Stack *s)
{
  for (int i = 0; i < s->top; ++i)
  {
    printf("%d ", s->elem[i]->data);
  }
  return;
}