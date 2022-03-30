#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
int *getLocaions(const char *s1, const char *s2)
{
  int *ret = (int *)malloc(sizeof(s1) * sizeof(int));
  for (unsigned int i = 0; i < sizeof(s1); ++i)
  {
    ret[i] = -1;
  }
  int cnt = 0;
  if (strlen(s1) < strlen(s2))
  {
    return NULL;
  }
  unsigned int i = 0;
  unsigned int j = 0;
  int temp;
  for (i = 0, j = 0; i < strlen(s1); ++i)
  {
    temp = i;
    while (s1[i] == s2[j] && j < strlen(s2))
    {
      ++j;
      ++i;
    }
    if (s1[i] != s2[j] && j != strlen(s2))
    {
      i = temp;
      j = 0;
    }
    else if (j == strlen(s2))
    {
      ret[cnt] = temp;
      j = 0;
      ++cnt;
    }
  }
  return ret;
}
char *leftAndRight(const char *s, int left, int right)
{
  if (right < left)
    return NULL;
  int lenOfs = strlen(s);
  char *a = (char *)malloc((lenOfs) * sizeof(char));
  strcpy(a, s);
  int tem = 0;
  for (int i = left; i < right; ++i)
  {
    a[tem] = s[i];
    tem++;
  }
  a[tem] = '\0';
  return a;
}
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
  int cnt = -1;
  int *work1 = getLocaions(in, oldstr);
  for (int i = 0; work1[i] != -1; ++i)
  {
    cnt++;
  } //从work[0]到work[cnt]这些数据是有效的
  int *work2 = (int *)malloc(sizeof(int) * strlen(in) * (cnt + 5));
  for (int i = 0; work1[i] != -1; ++i)
  {
    work2[i] = work1[i] + strlen(oldstr) - 1;
  }
  char *compare = (char *)malloc(sizeof(char) * strlen(in) * (cnt + 5));
  // strcat(compare, leftAndRight(in, 0, work1[0]));
  // for (int i = 1; i <= cnt; ++i)
  // {
  //   strcat(compare, newstr);
  //   strcat(compare, leftAndRight(in, work2[i - 1] + 2, work1[i]));
  // }
  printf("\n%s", compare);
  return 0;
}

int main()
{
  const char *s1 = (char *)malloc(MAXSIZE * sizeof(char));
  s1 = "abcdefbcdefbcdefffffbbb";
  const char *s2 = (char *)malloc(MAXSIZE * sizeof(char));
  s2 = "b";
  const char *s3 = (char *)malloc(MAXSIZE * sizeof(char));
  s3 = " *efgh* ";
  char *work = (char *)malloc(sizeof(int) * MAXSIZE);
  str_replace(s1, work, 15, s2, s3);
}