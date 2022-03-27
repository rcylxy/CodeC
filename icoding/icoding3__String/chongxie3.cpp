#define BLOCK_SIZE 4  // 可由用户定义的块大小
#define BLS_BLANK '#' // 用于空白处的补齐字符
#include <stdio.h>
#include <stdlib.h>

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

//--------------------------------------------//

int len(const char *s) //求字符串的长度
{
  int ret = 0;
  while (*(s++) != '\0')
    ret++;
  return ret;
}

void turnString(const char *s, BLString *ret) //将s这个普通字符串转变为ret这个块链串
{
  if (ret->head == NULL)
  {
    ret->head = (Block *)malloc(sizeof(Block));
  }
  int i, j;                             //由于最后一个节点的需要，我们升级i,j的作用域
  int recOfNowLen = 0;                  //初始化时记录遍历的所达到的长度
  int length = len(s);                  //给定字符串的长度
  int lenOfBlock = length / BLOCK_SIZE; //能取整数就直接取整数
  if (length % BLOCK_SIZE != 0)         //除不尽就+1
    lenOfBlock++;
  Block *p, *q; //这里不要忘记了ret还有尾指针，尾指针的位置很重要，p先保存ret的head
  for (i = 0; i < lenOfBlock; ++i)
  {
    q = (Block *)malloc(sizeof(Block)); //先把q这个节点准备好，让p进行连接
    for (j = 0; j < BLOCK_SIZE && recOfNowLen < length; ++j)
    {
      q->ch[j] = s[recOfNowLen];
      recOfNowLen++;
    }
    while (j < BLOCK_SIZE)
    {
      q->ch[j] = BLS_BLANK;
      j++;
    }

    if (i == 0)
    {
      ret->head = q;
      p = ret->head;
    }
    else
    {
      p->next = q;
      p = p->next;
      if (recOfNowLen == length)
      {
        ret->tail = q;
        p = NULL;
      }
    }
  }
  ret->len = lenOfBlock;
  return;
}

bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
  char *s = (char *)malloc(sizeof(char) * (len + 5));
  int i = 0, j = 0;
  Block *p = src.head;
  int temp = 0;
  for (i = 0; i < src.len; ++i)
  {
    for (j = 0; j < BLOCK_SIZE; ++j)
    {
      if (p->ch[j] == BLS_BLANK)
        goto A1;
      s[temp] = p->ch[j];
      temp++;
    }
    p = p->next;
  }
A1:
  s[temp] = '\0';
  int posMax = temp - 1;
  if (pos > posMax || len + pos > temp)
    return false;
  int pr = 0;
  char *q = (char *)malloc(sizeof(char) * (len + 5));
  for (int i = pos; i < pos + len; ++i)
  {
    q[pr] = s[i];
    pr++;
  }
  q[pr] = '\0';
  turnString(q, sub);
  return true;
}

void TestprintBLString(BLString *ret)
{
  int i = 0, j = 0;
  Block *p = ret->head;
  for (i = 0; i < ret->len; ++i)
  {
    for (j = 0; j < BLOCK_SIZE; ++j)
    {
      printf("%c", p->ch[j]);
    }
    printf(" ");
    p = p->next;
  }
}
int main()
{
  char *s = "abcdefghijklmnopqrstuvw";
  BLString ret;
  blstr_init(&ret);
  turnString(s, &ret);
  TestprintBLString(&ret);
  BLString sub;
  blstr_init(&sub);
  blstr_substr(ret, 0, 4, &sub);
  printf("\n");
  TestprintBLString(&sub);
}
