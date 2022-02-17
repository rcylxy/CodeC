#define MAX_SIZE 40
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char String[MAX_SIZE + 1];
typedef enum
{
  OK,
  ERROR
} Status;
Status StrAssign(String T, char *chars) /* 生成一个其值等于chars的串T */
{
  if (strlen(chars) > MAX_SIZE)
    return ERROR;
  T[0] = strlen(chars);
  for (int i = 1; i <= T[0]; ++i)
  {
    T[i] = *(chars + i - 1);
  }
  return OK;
}
Status StrCopy(String T, String S) /* 由串S复制得串T */
{
  for (int i = 0; i <= S[0]; ++i)
  {
    T[i] = S[i];
  }
  return OK;
}
bool StrEmpty(String S) /* 若S为空串,则返回TRUE,否则返回FALSE */
{
  return (S[0] == 0);
}
int StrCompare(String S, String T)
/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
{
  for (int i = 1; i <= S[0] && i <= T[0]; ++i)
  {
    if (S[i] != T[i])
      return T[i] - S[i];
  }
  return T[0] - S[0];
}
int StrLength(String S)
{
  return S[0];
}
Status ClearString(String S)
{
  S[0] = 0;
  return OK;
}
Status Concat(String T, String S1, String S2)
{
  if (S1[0] + S2[0] <= MAX_SIZE)
  {
    T[0] = S1[0] + S2[0];
    for (int i = 1; i <= S1[0]; ++i)
    {
      T[i] = S1[i];
    }
    for (int i = 1; i <= S2[0]; ++i)
    {
      T[S1[0] + i] = S2[i];
    }
    return OK;
  }
  else
  {
    T[0] = MAX_SIZE;
    for (int i = 1; i <= S1[0]; ++i)
    {
      T[i] = S1[i];
    }
    for (int i = 1; i <= MAX_SIZE; ++i)
    {
      T[S1[0] + i] = S2[i];
    }
    return ERROR;
  }
}
Status SubString(String Sub, String S, int pos, int len)
/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
{
  if (pos < 1 || pos > S[0] || len + pos - 1 > S[0])
    return ERROR;
  else
  {
    Sub[0] = len;
    for (int i = 1; i <= len; ++i)
    {
      Sub[i] = S[pos + len - 1];
    }
    return OK;
  }
}
int Index(String S, String T, int pos) //s is the main string;
{
  int i = pos;
  int j = 1;
  while (i <= S[0] - '0' && j <= T[0] - '0')
  {
    if (S[i] == T[j])
    {
      ++i;
      ++j;
    }
    else
    {
      i = i - j + 2; //隐含了一个++i的操作
      j = 1;
    }
  }
  if (j == T[0] - '0' + 1)
    return i - (T[0] - '0');
  else
    return 0;
}
bool StrInsert(String S, int pos, String T)
{
  int i;
  if (pos < 1 || pos > S[0] + 1)
    return ERROR;
  if (S[0] + T[0] <= MAX_SIZE)
  {
    S[0] += T[0];
    for (int i = S[0]; i >= pos; --i)
    {
      S[i + T[0]] = S[i];
    }
    for (int j = pos; j < pos + T[0]; ++j)
    {
      S[i] = T[i - pos + 1];
    }
    return true;
  }
  else
  {
    S[0] = MAX_SIZE;
    for (int i = MAX_SIZE; i >= pos; --i)
    {
      S[i + T[0]] = S[i];
    }
    for (int j = pos; j < pos + T[0]; ++j)
    {
      S[i] = T[i - pos + 1];
    }
    return false;
  }
}
Status StrDelete(String S, int pos, int len)
{
  int i;
  if (pos < 1 || pos > len - pos + 1 || len < 0)
  {
    return ERROR;
  }
  for (i = pos + len; i <= S[0]; ++i)
  {
    S[i - len] = S[i];
  }
  S[0] -= len;
  return OK;
}
Status Replace(String S, String T, String V)
{
  int i = 1;
  if (StrEmpty(T))
    return ERROR;
  do
  {
    i = Index(S, T, i);
    if (i)
    {
      StrDelete(S, i, StrLength(T));
      StrInsert(S, i, V);
      i += StrLength(V);
    }
  } while (i);
  return OK;
}
void StrPrint(String T)
{
  int i;
  for (i = 1; i <= T[0]; i++)
    printf("%c", T[i]);
  printf("\n");
}