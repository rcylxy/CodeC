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
const char *in = "lmopqrstuvxcdcdaasdf";
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
      Mystrcpy(out, leftAndRight(in, 0, location[i] - 1));
      out[outlen - 1] = '\0';
      if (Mystrlen(out) + lenOfnewstr > outlen)
        return 0;
      Mystrcat(out, newstr);
      ret++;
      i++;
    }
    else if (location[i] != ERROR)
    {
      Mystrcat(out, leftAndRight(in, location[i - 1] + lenOfoldstr, location[i] - 1)); // yuejie
      out[outlen - 1] = '\0';
      if (Mystrlen(out) + lenOfnewstr > outlen)
        return cnt;
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
  const char *oldstr = "cd";
  int outlen = 100;
  char *out = (char *)malloc(outlen * sizeof(char));
  const char *newstr = "f";
  printf("\ncount==%d\n", str_replace(in, out, outlen, oldstr, newstr));
  printf("out==%s", out);
  return 0;
}