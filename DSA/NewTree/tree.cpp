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
bool is_full(Stack *S);
void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  // x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false
void pre_order(BiTree root);
bool InitBiTree(BiTree *T);
bool CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
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
void pre_order(BiTree root)
{
  printf("%d ", root->data);
  return;
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
void PreOrderTraverse(BiTree T)
{
  if (T == NULL)
  {
    return;
  }
  pre_order(T);
  PreOrderTraverse(T->left);
  PreOrderTraverse(T->right);
  return;
}
void InOrderTraverse(BiTree T)
{
  if (T == NULL)
  {
    return;
  }
  InOrderTraverse(T->left);
  pre_order(T);
  InOrderTraverse(T->right);
  return;
}
void PostOrderTraverse(BiTree T)
{
  if (T == NULL)
  {
    return;
  }
  PostOrderTraverse(T->left);
  PostOrderTraverse(T->right);
  pre_order(T);
  return;
}
void pre_order_non_recursion(BiTree T)
{
  Stack S;
  init_stack(&S);
  // S.top = -1;
  BiTree p = T;
  // printf("%d", T->data);
  while (p || !is_empty(&S))
  {
    if (p->right)
      push(&S, p->right);
    if (p->left)
    {
      pre_order(p);
      p = p->left;
    }
    else if (p->left == NULL)
    {
      pre_order(p);
      if (!is_empty(&S))
      {
        pop(&S, &p);
      }
      else if (is_empty(&S))
        return;
    }
  }
}
void pre_order_his(BiTree root)
{
  Stack S;
  init_stack(&S);
  BiTree T = root;
  while (T || !is_empty(&S))
  {
    while (T)
    {
      pre_order(T);
      push(&S, T);
      T = T->left;
    }
    pop(&S, &T);
    T = T->right;
  }
}
int main()
{
  BiTree T;
  InitBiTree(&T);
  CreateBiTree(&T);
  printf("\n");
  printf("前序遍历:\n");
  PreOrderTraverse(T);
  printf("\n中序遍历:\n");
  InOrderTraverse(T);
  printf("\n后序遍历:\n");
  PostOrderTraverse(T);
  printf("\n我的前序遍历:\n");
  pre_order_non_recursion(T);
  printf("\n他的前序遍历:\n");
  pre_order_his(T);
}
/* test
1 2 3 -1 -1 4 -1 -1 5 6 7 -1 -1 8 -1 -1 9 -1 -1
*/