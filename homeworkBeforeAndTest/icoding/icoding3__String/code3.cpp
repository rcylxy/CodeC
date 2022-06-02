#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include "dsstring.h"

int Mystrlen(const char *S)
{
  int c = 0;
  while (*S++ != '\0')
    c++;
  return c;
}
void Mystrcat(char *a, const char *b) //把b放到a的后面
{
  while (*a != '\0')
  {
    a++;
  }
  while ((*a++ = *b++) != '\0')
    ;
  return;
}
void *Mymemset(void *s, int num, size_t outlen)
{
  if (s == NULL || outlen < 0)
    return NULL;
  char *tmpS = (char *)s;
  while (outlen-- > 0)
    *tmpS++ = num;
  return s;
}
char *Mystrncat(char *dest, const char *source, int n)
{

  char *ret = dest;

  while (*dest != '\0')
  {
    dest++;
  }
  while (n && (*dest++ = *source++))
  {
    n--;
  }
  return ret;
}
int Mystrncmp(const char *str1, const char *str2, int size)
{
  for (int i = 0; i < size; ++i)
  {
    if (str1[i] > str2[i])
    {
      return 1;
    }
    else if (str1[i] < str2[i])
    {
      return -1;
    }
    if (str1[i] == 0 || str2[i] == 0)
    {
      break;
    }
  }
  return 0;
}
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
  Mymemset(out, 0, outlen);
  int count = 0;
  for (int i = 0; i < Mystrlen(in); i++)
  {
    if (Mystrncmp(in + i, oldstr, Mystrlen(oldstr)) == 0 && (Mystrlen(out) + Mystrlen(newstr) < outlen))
    {
      //查找到目标字符串
      Mystrcat(out, newstr);
      //把新字符串贴到缓冲字符串里
      i += Mystrlen(oldstr) - 1;
      count++;
    }
    else
    {                            //如果没有找到
      Mystrncat(out, in + i, 1); //将该字符写入缓冲字符串数组
    }
    if (Mystrlen(out) + 1 >= outlen)
      break;
  }
  return count;
}