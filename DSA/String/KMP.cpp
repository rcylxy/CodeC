#define MAX_SIZE 40
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char String[MAX_SIZE + 1];
typedef struct
{
  String P;
  int length;
} String1;
typedef enum
{
  OK,
  ERROR
} Status;
// void getNext(int next[], String1 S) //求next表
// {
//   //j是后缀末尾处，标志着子串的结束。
//   //next[i]就是以i号元素为结尾的子串中的最长相等前后缀的长度
//   //k是最长的前缀末尾，是某处要回退到的位置
//   next[0] = -1;
//   int j = 0;
//   int k = -1;
//   while (j < S.length - 1)
//   {
//     if (k == -1)
//     {
//       next[++j] = 0;
//       k = 0;
//     }
//     else if (S.S[j] == S.S[k]) //j是顺序依次向后移动的
//     {                          //next[j+1] == k + 1 == next[j] + 1
//       next[++j] = ++k;
//     }
//     else if (S.S[j] != S.S[k])
//     {
//       k = next[k];
//     }
//   }
// }
void getNext(int next[], String1 P)
{
  int k = -1;
  int j = 0;
  next[0] = -1;
  while (j < P.length)
  {
    if (k == -1 || P.P[k] == P.P[j])
    {
      if (P.P[++j] == P.P[++k])
      {
        next[j] = next[k];
      }
      else
      {
        next[j] = k;
      }
    }
    else if (P.P[k] != P.P[j])
    {
      k = next[k];
    }
  }
}
int KMP(String1 ts, String1 ps)
{
  String1 t = ts;
  String1 p = ps;
  int i = 0;
  int j = 0;
  int next[MAX_SIZE];
  getNext(next, p);
  while (i < t.length && j < p.length)
  {
    if (j == -1)
    {
      i++;
      j = 0;
    }
    else if (t.P[i] == p.P[j])
    {
      i++;
      j++;
    }
    else
    {
      j = next[j];
    }
  }
  if (j == p.length)
    return i - j;
  else
    return -1;
}