#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Stack_Size 50
typedef int ElemType;
typedef struct
{
  ElemType elem[Stack_Size];
  int top;
} Stack;
bool StackFull(Stack *S);
bool StackEmpty(Stack *S);
bool push(Stack *S, ElemType x);
bool pop(Stack *S, ElemType *x);
void init_stack(Stack *S);
void TraverseStack(Stack *S);
bool StackFull(Stack *S)
{
  return S->top == Stack_Size - 1;
}
bool StackEmpty(Stack *S)
{
  return S->top == -1;
}
bool push(Stack *S, ElemType x)
{
  if (StackFull(S))
    return false;
  S->top++;
  S->elem[S->top] = x;
  return true;
}
bool pop(Stack *S, ElemType *x)
{
  if (StackEmpty(S))
    return false;
  *x = S->elem[S->top];
  S->top--;
  return true;
}
void init_stack(Stack *S)
{
  S->top = -1;
}
void TraverseStack(Stack S)
{
  while (S.top != -1)
  {
    printf("%d ", S.elem[S.top]);
    S.top--;
  }
  return;
}