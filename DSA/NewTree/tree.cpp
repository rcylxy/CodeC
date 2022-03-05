#include "tree.h"
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
  S.top = -1;
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
  S.top = -1;
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
bool path_my(BiTNode *root, BiTNode *node, Stack *s)
{
  if (root == node)
  {
    push(s, root);
    return true;
  }
  if (!root || !node || !is_empty(s))
    return false;
  BiTree p = root, q = NULL;
  while (!is_empty(s) || p != NULL)
  {
    while (p)
    {
      push(s, p);
      if (p == node)
        return true;
      p = p->left;
    }
    top(s, &p);
    if (!p->right || p->right == q)
    {
      q = p;
      pop(s, &p);
      p = NULL;
    }
    else
    {
      p = p->right;
    }
  }
  return false;
}

void printStack(Stack *s)
{
  while (!is_empty(s))
  {
    BiTree T;
    pop(s, &T);
    printf("%d ", T->data);
  }
  return;
}
BiTNode *nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q)
{
  Stack s1;
  init_stack(&s1);
  s1.top = -1;
  path(root, p, &s1);
  printStack(&s1);
  printf("\n");
  Stack s2;
  init_stack(&s2);
  s2.top = -1;
  path(root, q, &s2);
  printStack(&s2);
}
int main()
{
  printf("请输入整型二叉树结点，以-1为虚结点！\n");
  BiTree T;
  BiTNode *node = (BiTNode *)malloc(sizeof(BiTNode));
  InitBiTree(&T);
  CreateBiTree(&T);
  printf("\n");
  printf("前序遍历:\n");
  PreOrderTraverse(T);
  printf("\n中序遍历:\n");
  InOrderTraverse(T);
  printf("\n后序遍历:\n");
  PostOrderTraverse(T);
  printf("\n改进前非递归前序遍历:\n");
  pre_order_non_recursion(T);
  printf("\n改进后非递归前序遍历:\n");
  pre_order_his(T);
  printf("\n");
  printf("是否找到路径？");
  Stack s;
  init_stack(&s);
  s.top = -1;
  node = T->left->left->right->left;
  int outcome = path_my(T, node, &s);
  printf("\n%d\n", outcome);
  if (outcome != 0)
  {
    printf("路径是：");
    printStack(&s);
  }
  printf("\n");
  BiTNode *p = T->left->right;
  BiTNode *q = T->left->left;
  nearest_ancestor(T, p, q);
}
/* test
1 2 3 -1 -1 4 -1 -1 5 6 7 -1 -1 8 -1 -1 9 -1 -1
1 2 3 4 -1 -1 5 6 -1 -1 -1 7 -1 8 -1 -1 9 -1 10 11 -1 -1 12 -1 -1
*/