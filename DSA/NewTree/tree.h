#pragma once
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
bool is_empty(Stack *S);
bool is_full(Stack *S);
void init_stack(Stack *S);
bool push(Stack *S, ElemType x);
bool pop(Stack *S, ElemType *px);
bool top(Stack *S, ElemType *px);
void pre_order(BiTree root);
bool InitBiTree(BiTree *T);
bool CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void pre_order_non_recursion(BiTree T);
void pre_order_his(BiTree root);
bool path(BiTNode *root, BiTNode *node, Stack *s);
BiTNode *nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q);