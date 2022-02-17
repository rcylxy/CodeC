#define ClearBiTree DestroyBiTree
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#include <Windows.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char TElemType;
typedef int Status;
int treeIndex = 1;
// binary tree BiTNode
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//为什么BiTree是一个指向BiTNode的一个指针呢，其实是BiTNode的数组
//将树的节点作为数组存储，这就是二叉树的实质

Status visit(TElemType e)
{
  printf("%c ", e);
  return OK;
}
Status InitBiTree(BiTree *T)
{
  *T = NULL;
  return OK;
}
Status DestroyBiTree(BiTree *T)
{
  if (*T)
  {
    if ((*T)->lchild)
    {
      DestroyBiTree(&((*T)->lchild));
    }
    if ((*T)->rchild)
    {
      DestroyBiTree(&((*T)->rchild));
    }
    free(*T);
    *T = NULL;
  }
  return OK;
}
Status CreateBiTree(BiTree *T)
{
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '#')
    *T = NULL;
  else
  {
    *T = (BiTree)malloc(sizeof(BiTNode));
    if (!*T)
      exit(-1);
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
  }
  return OK;
}
bool BiTreeEmpty(BiTree T)
{
  return (!T);
}
int BiTreeDepth(BiTree T)
{
  int i, j;
  if (T == NULL)
    return 0;
  if (T->lchild)
  {
    i = BiTreeDepth(T->lchild);
  }
  else
  {
    i = 0;
  }
  if (T->rchild)
  {
    j = BiTreeDepth(T->rchild);
  }
  else
  {
    j = 0;
  }
  return i > j ? i + 1 : j + 1;
}
TElemType Root(BiTree T)
{
  if (BiTreeEmpty(T))
    return NULL;
  else
    return T->data;
}
TElemType Value(BiTree p)
{
  return p->data;
}
void Assign(BiTree p, TElemType value)
{
  p->data = value;
}
void PreOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  visit(T->data);
  PreOrderTraverse(T->lchild);
  PreOrderTraverse(T->rchild);
  return;
}
void InOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild);
  visit(T->data);
  InOrderTraverse(T->rchild);
  return;
}
void PostOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  visit(T->data);
  return;
}
Status Copy(BiTree T, BiTree *P)
{
  if (T == NULL)
  {
    return OK;
  }
  else
  {
    *P = (BiTree)malloc(sizeof(BiTNode));
    (*P)->data = T->data;
    Copy(T->lchild, &((*P)->lchild));
    Copy(T->rchild, &((*P)->rchild));
    return OK;
  }
}
int NodeCount(BiTree T)
{
  if (T == NULL)
    return 0;
  else
    return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
}
int main(int argc, char *argv[])
{
  int i;
  BiTree T;
  BiTree P;
  InitBiTree(&P);
  InitBiTree(&T);
  printf("\n输入带虚结点的二叉树结点\n");
  CreateBiTree(&T);
  printf("\n树是空树吗:%d\n", BiTreeEmpty(T));
  printf("\n树的深度是:%d\n", BiTreeDepth(T));
  printf("\n树的根值是%c\n", Root(T));
  printf("\n树的节点数是%d\n", NodeCount(T));
  printf("\n前序遍历二叉树\n");
  PreOrderTraverse(T);
  printf("\n中序遍历二叉树\n");
  InOrderTraverse(T);
  printf("\n后序遍历二叉树\n");
  PostOrderTraverse(T);
  Sleep(1000);
  Copy(T, &P);
  printf("\ncopy树是空树吗:%d\n", BiTreeEmpty(P));

  ClearBiTree(&T);
  printf("\n自动清除二叉树\n");
  i = Root(T);
  if (!i)
    printf("树空，无根\n");
  return 0;
}