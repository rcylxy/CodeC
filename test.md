```cpp
#include "String.h"
#include <string.h>
/*in， 原始字符串，保持不变
out, 存放替换结果的字符串
outlen，out空间的大小
oldstr，要替换的旧字符串
newstr，替换成的新字符串
函数返回成功替换的次数，即有多少个子串被成功替换
在替换过程中，任何情况下所得字符串（及'\0'）不应该超过 outlen，
如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，
两次替换后得 "aaabbb333333c"，
此时字符串占用空间为14字节。如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。
此时函数应该返回 2, out指向的串为 "aaabbb333333c"
再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "bb"，newstr 为 "123456"，
进行替换后所得的串应该为 "aaa123456" （长度为9）与结束符一共占 10 个字节，此时函数应该返回 1。*/
int MyStrLen(const char *S)
{
  int cnt = -1;
  while (S[++cnt] != '\0')
    ;
  return cnt;
}
int StrSearch(const char *in, const char *oldstr)
{
  //  int lenOfIn = MyStrLen(in);
  int lenOfoldstr = MyStrLen(oldstr);
  const char *q = in;     // in，原始字符串，保持不变
  const char *p = oldstr; //要搜索的旧字符串
  int i = 0, j = 0;
  for (i = 0; q[i] != '\0' && p[j] != '\0'; ++i)
  {
    if (q[i] == p[j])
    {
      ++j;
    }
    else if (q[i] != p[j])
    {
      j = 0;
    }
  }
  if (p[j] == '\0')
  {
    return i - lenOfoldstr;
  }
}
// int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
// {
//   int cnt = 0;
//   int lenOfIn = MyStrLen(in);
//   int lenOfoldstr = MyStrLen(oldstr);
//   int lenOfnewstr = MyStrLen(newstr);
//   const char *q = in;     // in，原始字符串，保持不变
//   const char *p = oldstr; //要替换的旧字符串
//   //在in里寻找q
//   // int i = 0, j = 0;
//   // for (i = 0; q[i] != '\0' && p[j] != '\0'; ++i)
//   // {
//   //   if (q[i] == p[j])
//   //   {
//   //     ++j;
//   //   }
//   //   else if (q[i] != p[j])
//   //   {
//   //     j = 0;
//   //   }
//   // }
//   // if (p[j] == '\0')
//   // {
//   //   if ((lenOfIn - lenOfoldstr + lenOfnewstr) > outlen)
//   //     return cnt;
//   //   else
//   //   {
//   //     for (int k = i - lenOfoldstr; k <= i - lenOfoldstr + lenOfnewstr; ++k)
//   //     {
//   //     }
//   //   }
//   // }

//   // return cnt;
// }
int main()
{

  const char *in = "cdabc";
  char *out = "abc";
  int outlen = 5;
  const char *oldstr = "ab";
  const char *newstr = "abc";
  printf("%d", StrSearch(in, oldstr));
}
```

```cpp
  // int lenOfin = MyStrLen(in);
  // int lenOfout = MyStrLen(out);
  // int lenOfnewstr = MyStrLen(newstr);

  // // if (lenOfin - lenOfoldstr + lenOfnewstr > outlen)
  // if (lenOfout + lenOfnewstr > outlen)
  //   return -1;            //代表不可能的值
```

(2022.2.15.21:30)
```cpp
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
  int lenOfoldstr = Mystrlen(oldstr);
  int lenOfnewstr = Mystrlen(newstr);
  getAllLocation(in, oldstr);
  printLocation();
  int i = 0;
  while (location[i] != ERROR)
  {
    if (i == 0)
    {
      Mystrcpy(out, leftAndRight(in, 0, location[i] - 1));
      Mystrcat(out, newstr);
      i++;
    }
    else if (location[i + 1] == ERROR)
    {
      Mystrcat(out, newstr);
      Mystrcat(out, leftAndRight(in, (location[i]) + lenOfnewstr + 1, lenOfIn - 1));
      i++;
    }
    else
    {
      Mystrcat(out, newstr); // const char *in = "abcdabcdabcdh";
      Mystrcat(out, leftAndRight(in, (location[i]) + lenOfnewstr, (location[i + 1]) - 1));
      i++;
    }
  }

  return cnt;
}
```
```cpp
#include <stdio.h>
#include <stdlib.h>
#define ERROR -2
int Mystrlen(const char *S)
{
  int c = 0;
  while (*S++ != '\0')
    c++;
  return c;
}
int max(int a, int b)
{
  return a > b ? a : b;
}
const char *in = "habcdabcdabcd";
int lenOfIn = Mystrlen(in);
int cnt = 0; //次数
int *location = (int *)malloc(sizeof(lenOfIn + 1) * sizeof(int));
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
int Mystrstr(const char *in, const char *oldstr) //在in里寻找oldest
{
  const char *q = in;     // in，原始字符串，保持不变
  const char *p = oldstr; //要替换的旧字符串
  //在in里寻找q
  int i = 0, j = 0;
  for (i = 0; q[i] != '\0' && p[j] != '\0'; ++i)
  {
    if (q[i] == p[j])
    {
      ++j;
    }
    else if (q[i] != p[j])
    {
      j = 0;
    }
  }
  if (p[j] == '\0')
  {
    // return i - lenOfoldstr;
    return i; // return到下标
  }
  return -1; //代表不存在
}
void Mystrcpy(char *a, const char *b)
{
  while ((*a++ = *b++) != '\0')
  {
    ;
  }
}
char *left(const char *s, int n)
{
  int lenOfs = Mystrlen(s);
  char *a = (char *)malloc((lenOfs) * sizeof(char));
  Mystrcpy(a, s);
  int tem = 0;
  for (int i = n; s[i] != '\0'; ++i)
  {
    a[tem] = s[i];
    tem++;
  }
  a[tem] = '\0';
  return a;
}
char *leftAndRight(const char *s, int left, int right)
{
  if (right < left)
    return NULL;
  int lenOfs = Mystrlen(s);
  char *a = (char *)malloc((lenOfs) * sizeof(char));
  Mystrcpy(a, s);
  int tem = 0;
  for (int i = left; i <= right; ++i)
  {
    a[tem] = s[i];
    tem++;
  }
  a[tem] = '\0';
  return a;
}
int getAllLocation(const char *in, const char *oldstr)
{

  int lenOfoldstr = Mystrlen(oldstr);
  int temp = Mystrstr(in, oldstr);
  if (temp == -1 || in == NULL)
  {
    location[cnt] = ERROR;
    return -1;
  }
  else if (cnt == 0)
  {
    location[cnt] = temp - lenOfoldstr;
    cnt++;
  }
  else if (cnt != 0)
  {
    location[cnt] = temp + location[cnt - 1];
    cnt++;
  }
  getAllLocation(left(in, temp), oldstr);
  return 0;
}
void printLocation()
{
  for (int i = 0; location[i] != ERROR; ++i)
  {
    printf("%d ", location[i]);
  }
  return;
}
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
  int ret = 0;
  int lenOfoldstr = Mystrlen(oldstr);
  int lenOfnewstr = Mystrlen(newstr);
  getAllLocation(in, oldstr);
  printf("location[i]==");
  printLocation();
  int i = 0;
  while (location[i] != ERROR)
  {
    if (i == 0)
    {
      if (Mystrlen(out) + Mystrlen(leftAndRight(in, 0, location[i] - 1)) + 1 > outlen)
      {
        out[max(outlen - 1, Mystrlen(in) - 1)] = '\0';
        Mystrcpy(out, leftAndRight(in, 0, max(outlen - 1, Mystrlen(in) - 1) - 1));
        return 0;
      }
      Mystrcpy(out, leftAndRight(in, 0, location[i] - 1));
      out[Mystrlen(out) + 1] = '\0';
      if (Mystrlen(out) + lenOfnewstr + 1 > outlen)
      {
        out[Mystrlen(out) + 1] = '\0';
        Mystrcpy(out, leftAndRight(in, 0, outlen - 2));
        return 0;
      }
      Mystrcat(out, newstr);
      ret++;
      i++;
    }
    else if (location[i] != ERROR)
    {
      Mystrcat(out, leftAndRight(in, location[i - 1] + lenOfoldstr, location[i] - 1)); // yuejie
      out[Mystrlen(out) + 1] = '\0';
      if (Mystrlen(out) + lenOfnewstr + 1 > outlen)
      {
        return cnt;
      }
      Mystrcat(out, newstr);
      i++;
      ret++;
    }
  }
  if (location[i] == ERROR)
  {
    if (Mystrlen(out) + lenOfIn - location[i - 1] + lenOfoldstr + 2 > outlen)
    {
      Mystrcat(out, leftAndRight(in, location[i - 1] + lenOfoldstr, location[i - 1] + lenOfoldstr + outlen - Mystrlen(out) - 2));
      out[outlen - 1] = '\0';
    }
    Mystrcat(out, leftAndRight(in, location[i - 1] + lenOfoldstr, lenOfIn));
    out[Mystrlen(out) + 1] = '\0';
  }

  return ret;
}
int main(int argc, char *argv[])
{
  location[0] = ERROR;
  const char *oldstr = "a";
  int outlen = 10;
  char *out = (char *)malloc(outlen * sizeof(char));
  const char *newstr = "fds";
  printf("\ncount==%d\n", str_replace(in, out, outlen, oldstr, newstr));
  printf("out==%s", out);
  return 0;
}
```