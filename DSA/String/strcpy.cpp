#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -2
const char *in = "abcdabcdabcdh";
int lenOfIn = strlen(in);
int cnt = 0; //次数
int *location = (int *)malloc(sizeof(lenOfIn + 1) * sizeof(int));
const char *oldstr = "h";
int outlen = 300;
char *out = (char *)malloc(outlen * sizeof(char));
const char *newstr = "f";
void Mystrcpy(char *a, const char *b)
{
  while ((*a++ = *b++) != '\0')
  {
    ;
  }
}
char *left(const char *s, int n)
{
  int lenOfs = strlen(s);
  int c = 0;
  char *a = (char *)malloc((lenOfs) * sizeof(char));
  Mystrcpy(a, s);
  int temp = 0;
  for (int i = n; s[i] != '\0'; ++i)
  {
    a[temp] = s[i];
    temp++;
  }
  return a;
}
char *leftAndRight(const char *s, int left, int right)
{
  int lenOfs = strlen(s);
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
int main()
{
  location[0] = ERROR;
  strcpy(out, in);
  printf("%s", out);
  printf("\n%d", strlen(out));
}