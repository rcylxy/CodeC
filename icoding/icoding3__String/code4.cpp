#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 4  // 可由用户定义的块大小
#define BLS_BLANK '#' // 用于空白处的补齐字符
typedef struct _block
{
  char ch[BLOCK_SIZE]; //块的数据域
  struct _block *next; //块的指针域
} Block;
typedef struct
{
  Block *head; // 串的头指针
  Block *tail; // 串的尾指针
  int len;     // 串的当前长度
} BLString;
//字符串初始化函数：
void blstr_init(BLString *T)
{
  T->len = 0;
  T->head = NULL;
  T->tail = NULL;
}
int Mystrlen(const char *S)

{
  int c = 0;
  while (*S++ != '\0')
    c++;
  return c;
}
int Mystrcpy(BLString *T, const char *s)
{
  if (T->head == NULL)
    T->head = (Block *)malloc(sizeof(Block));
  if (T->tail == NULL)
    T->tail = (Block *)malloc(sizeof(Block));

  int sum = 0, temp, j = 0, len = Mystrlen(s);
  Block *p, *q;
  p = T->head;
  if (len == 0)
    return -1;
  T->len = len;
  int allocate = len / BLOCK_SIZE + 1;
  if (len % BLOCK_SIZE == 0)
    allocate--;
  for (int i = 0; i < allocate; ++i)
  {
    temp = sum;
    q = (Block *)malloc(sizeof(Block));
    if (q == NULL)
    {
      return -1;
    }
    if (i == allocate - 1)
    {
      int cur = 0;
      for (j = temp; j < temp + BLOCK_SIZE; ++j)
      {
        if (s[j] != '\0')
        {
          q->ch[cur] = s[j];
        }
        if (s[j] == '\0')
          break;
        cur++;
      }
      while (cur < BLOCK_SIZE)
      {
        q->ch[cur] = BLS_BLANK;
        cur++;
      }
      T->tail = q;
      p->next = q;
      q->next = NULL;
    }
    else
    {
      int cur = 0;
      for (j = temp; j < temp + BLOCK_SIZE; ++j)
      {
        sum++;
        q->ch[cur] = s[j];
        cur++;
      }
      p->next = q;
      p = p->next;
    }
  }
  return 1;
}
bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
  int subscriptOfBlock = pos / BLOCK_SIZE; //定位块的下标，从0开始
  int elseOfNum = pos % BLOCK_SIZE;        //定位位置在块中的位置，从0开始
  int cntsob = 0;
  Block *p = (Block *)malloc(sizeof(Block));
  p = src.head;
  if (len < 1 || pos < 0 || pos >= src.len)
    return false;
  while (p && cntsob <= subscriptOfBlock)
  {
    p = p->next;
    cntsob++;
  }
  if (!p)
    return false;
  char *temp = (char *)malloc((len + 5) * sizeof(char));
  int i = 0;
  while (i < len)
  {
    if (elseOfNum < BLOCK_SIZE)
    {
      if (p->ch[elseOfNum] == BLS_BLANK)
        break;
      temp[i++] = p->ch[elseOfNum++];
    }
    else if (elseOfNum >= BLOCK_SIZE)
    {
      p = p->next;
      elseOfNum = 0;
      if (!p)
        return false;
    }
  }
  temp[i] = '\0';
  Mystrcpy(sub, temp);
  return true;
}
void printString(BLString *T)
{
  Block *p = T->head->next;
  int cur;
  while (p != NULL)
  {
    for (cur = 0; cur < BLOCK_SIZE; ++cur)
    {
      printf("%c ", p->ch[cur]);
    }
    p = p->next;
  }
}
int main()
{
  BLString *T;
  T = (BLString *)malloc(sizeof(BLString));
  const char *s = "abcd";
  blstr_init(T);
  Mystrcpy(T, s);
  printString(T);
  BLString *sub;
  sub = (BLString *)malloc(sizeof(BLString));
  const char *ch = "";
  blstr_init(sub);
  Mystrcpy(sub, ch);

  if (blstr_substr(*T, 0, 2, sub) == false)
  {
    printf("\n");
    printf("失败！\n");
  }
  else
  {
    printf("\n\n");
    printString(sub);
  }
  return 0;
}
