#include <stdio.h>
int myStrLen(const char *s)
{
  int len = 0;
  while (*s++ != '\0')
    len++;
  return len;
}
int isNoneRepeat(const char *s)
{
  int len = myStrLen(s);
  for (int i = 0; i < len; ++i)
  {
    for (int j = 0; j < len; ++j)
    {
      if (s[i] == s[j] && i != j)
        return 0;
    }
  }
  return 1;
}
int lengthOfLongestSubstring(char *s)
{
  int ret = 1;
  int i = 0;
  int j = 0;
  return ret;
}

int main(int argc, char *argv[])
{
  const char *s = "abcdefgabcdefg";
  printf("%d\n", myStrLen(s));
  const char *test = "abcd";
  printf("%d\n", isNoneRepeat(test));
}