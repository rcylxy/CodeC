#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
typedef int StackEntry;
typedef struct stack
{
  StackEntry data[MAX_SIZE];
  int top; // max_under name
} Stack, *StackPtr;
typedef enum
{
  success,
  stackoverflow,
  stackunderflow,
  error
} Status;
int Stack_Full(StackPtr s);
int Stack_Empty(StackPtr s);
Status Stack_Init(StackPtr s);
Status Stack_Push(StackPtr s, StackEntry item);
Status Stack_Pop(StackPtr s, StackEntry *item);
Status Stack_Top(StackPtr s, StackEntry *item);
Status ClearStack(StackPtr s);
int StackLength(StackPtr s);
Status StackPrint(StackPtr s);
int main(int argc, char *argv[])
{
  Stack s;
  Stack_Init(&s);
  int opt;
  printf("/**********************\n");
  printf("1.入栈\n");
  printf("2.出栈\n");
  printf("3.取栈顶元素\n");
  printf("4.清空栈的元素\n");
  printf("5.取栈长\n");
  printf("6.出栈打印所有元素\n");
  printf("7.退出\n");
  printf("/**********************\n");
  while (1)
  {

    printf("请输入您的选择\n");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
    {
      int tmp1;
      int mnt;
      printf("输入要入栈的元素的个数\n");
      scanf("%d", &mnt);
      printf("输入要入栈的元素\n");
      for (int i = 0; i < mnt; ++i)
      {
        scanf("%d", &tmp1);
        Stack_Push(&s, tmp1);
      }
      break;
    }
    case 2:
    {
      int tmp2;
      Stack_Pop(&s, &tmp2);
      printf("出栈的元素是%d\n", tmp2);
      break;
    }
    case 3:
    {
      int tmp3;
      Stack_Top(&s, &tmp3);
      printf("栈顶的元素是%d\n", tmp3);
      break;
    }
    case 4:
    {
      ClearStack(&s);
      printf("清空成功\n");
      break;
    }
    case 5:
    {
      int tmp5;
      tmp5 = StackLength(&s);
      printf("栈长是%d\n", tmp5);
      break;
    }
    case 6:
    {
      StackPrint(&s);
      printf("\n");
      break;
    }
    case 7:
    {
      exit(0);
    }
    default:
    {
      printf("您输入有误\n");
      break;
    }
    }
  }
}
int Stack_Full(StackPtr s)
{
  return (s->top == MAX_SIZE - 1);
}
int Stack_Empty(StackPtr s)
{
  return (s->top == -1);
}
Status Stack_Init(StackPtr s)
{
  s->top = -1;
  return success;
}
Status Stack_Push(StackPtr s, StackEntry item)
{
  Status outcome = success;
  if (Stack_Full(s))
    outcome = stackoverflow;
  else
  {
    s->top++;
    s->data[s->top] = item;
  }
  return outcome;
}
Status Stack_Pop(StackPtr s, StackEntry *item)
{
  Status outcome = success;
  if (Stack_Empty(s))
    outcome = stackunderflow;
  else
  {
    *item = s->data[s->top];
    s->top--;
  }
  return outcome;
}
Status Stack_Top(StackPtr s, StackEntry *item)
{
  Status outcome = success;
  if (Stack_Empty(s))
    outcome = stackunderflow;
  else
  {
    *item = s->data[s->top];
  }
  return outcome;
}
Status ClearStack(StackPtr s)
{
  s->top = -1;
  return success;
}
int StackLength(StackPtr s)
{
  return s->top + 1;
}
Status StackPrint(StackPtr s) //出栈
{
  if (Stack_Empty(s))
    return error;
  int i = s->top;
  while (i >= 0)
  {
    printf("%d ", s->data[i]);
    i--;
  }
}
