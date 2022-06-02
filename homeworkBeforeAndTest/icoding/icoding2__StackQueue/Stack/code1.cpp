#include "stack.h"
/*请使用已定义好的栈完成后缀表达式计算：
(1)如果是操作数，直接入栈
(2)如果是操作符op，连续出栈两次，得到操作数x 和 y,计算 x op y，并将结果入栈。
后缀表达式示例如下：
9  3  1  -  3  *  +  10  2  /  +
13  445  +  51  /  6  -
操作数、操作符之间由空格隔开，操作符有 +，-，*, /, %共 5 种符号，所有操作数都为整型。*/
int compute_reverse_polish_notation(char *str)
{
  Stack S;
  init_stack(&S);
  int numToPush = 0;
  int i = 0;
  int final;
  while (str[i] != '\0')
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      numToPush = numToPush * 10 + (str[i] - '0');
      if (str[i + 1] == ' ')
        push(&S, numToPush);
      i++;
    }
    else if (str[i] == ' ')
    {
      i++;
      numToPush = 0;
    }
    else
    {
      int a;
      pop(&S, &a);
      int b;
      pop(&S, &b);
      switch (str[i])
      {
      case '+':
      {
        push(&S, a + b);
        i++;
        break;
      }
      case '-':
      {
        push(&S, b - a);
        i++;
        break;
      }
      case '*':
      {
        push(&S, b * a);
        i++;
        break;
      }
      case '/':
      {
        push(&S, b / a);
        i++;
        break;
      }
      case '%':
      {
        push(&S, b % a);
        i++;
        break;
      }
      }
    }
  }
  pop(&S, &final);
  return final;
}
int main()
{
  char str[] = "13 445 + 51 / 6 -";
  printf("%d", compute_reverse_polish_notation(str));
}