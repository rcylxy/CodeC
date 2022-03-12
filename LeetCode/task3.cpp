#include <stdio.h>
#include <stdlib.h>
int myStrLen(char *s)
{
  int len = 0;
  while (s[len++] != '\0')
    ;
  return len - 1;
}
int isNoneRepeat(char *s)
{
  int i = 0, j = 0;
  int len = myStrLen(s);
  int backet[300] = {0};
  for (int i = 0; s[i] != '\0'; i++)
  {
    backet[s[i]]++;
    if (backet[s[i]] > 1)
      return 0;
  }
  return 1;
}
char *leftAndRight(char *s, int left, int right)
{
  int len = myStrLen(s);
  char *ret = (char *)malloc((len + 10) * sizeof(char));
  int cnt = 0;
  for (int i = left; i <= right; ++i)
  {
    ret[cnt] = s[i];
    cnt++;
  }
  ret[cnt + 1] = '\0';
  return ret;
}
int lengthOfLongestSubstring(char *s)
{
  int max = 1;
  int len = myStrLen(s);
  int i = 0;
  int j = 0;
  if (len == 0)
    return 0;
  for (i = 0; i < len; ++i)
  {
    if (s[i] == s[i + 1])
    {
      continue;
    }

    for (j = i; j < len && i <= j; ++j)
    {
      if (i < j)
        if (isNoneRepeat(leftAndRight(s, i, j))) // is noneRepeat subString
        {
          max = max > (j - i + 1) ? max : (j - i + 1);
        }
    }
  }
  return max;
}

int main(int argc, char *argv[])
{
  char *s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnSTUV";
  char *test = "abcd";
  printf("%d\n", isNoneRepeat(test));
  printf("%d", lengthOfLongestSubstring(s));
}