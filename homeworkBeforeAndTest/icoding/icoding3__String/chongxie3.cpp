#define BLOCK_SIZE 4  // 可由用户定义的块大小
#define BLS_BLANK '#' // 用于空白处的补齐字符
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int turnString(BLString *ret, const char *s) //将s这个普通字符串转变为ret这个块链串
{
  if (ret->head == NULL)
  {
    ret->head = (Block *)malloc(sizeof(Block));
  }
  int i, j;               //由于最后一个节点的需要，我们升级i,j的作用域
  int recOfNowLen = 0;    //初始化时记录遍历的所达到的长度
  int length = strlen(s); //给定字符串的长度
  if (length == 0)
    return 0;
  int lenOfBlock = length / BLOCK_SIZE; //能取整数就直接取整数
  if (length % BLOCK_SIZE)              //除不尽就+1
    lenOfBlock++;
  ret->len = length;
  Block *p, *q; //这里不要忘记了ret还有尾指针，尾指针的位置很重要，p先保存ret的head
  for (i = 0; i < lenOfBlock; ++i)
  {
    q = (Block *)malloc(sizeof(Block)); //先把q这个节点准备好，让p进行连接
    if (!q)
      return 0;
    for (j = 0; j < BLOCK_SIZE && recOfNowLen < length; ++j)
    {
      q->ch[j] = s[recOfNowLen];
      recOfNowLen++;
    }
    if (recOfNowLen == length)
    {
      ret->tail = q;
      q->next = NULL;
    }
    for (; j < BLOCK_SIZE; ++j)
    {
      q->ch[j] = BLS_BLANK;
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
    }
  }
  return 1;
}
bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
  if (pos < 0 || pos >= src.len || len < 1)
    return false;
  char *s = (char *)malloc(sizeof(char) * (len + 5));
  char *work = (char *)malloc(sizeof(char) * (len + 5));
  Block *a = src.head;
  int i;

  printf("\n");
  //   TestprintBLString(&src);
  int cnt = 0;
  while (a)
  {
    for (i = 0; i < BLOCK_SIZE; ++i)
    {
      s[cnt] = a->ch[i];
      cnt++;
    }
    a = a->next;
  }
  s[cnt] = '\0';
  cnt = 0;
  if (pos + len > src.len)
  {
    for (int i = pos; i < src.len; ++i)
    {
      work[cnt] = s[i];
      ++cnt;
    }
    work[cnt] = '\0';
    turnString(sub, work);

    return 1;
  }
  for (int i = pos; i < pos + len; ++i)
  {
    work[cnt] = s[i];
    ++cnt;
  }
  work[cnt] = '\0';
  turnString(sub, work);
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
  const char *s = "abcdefijkw";
  BLString ret;
  blstr_init(&ret);
  turnString(&ret, s);
  TestprintBLString(&ret);
  BLString sub;
  blstr_init(&sub);
  blstr_substr(ret, 1, 5, &sub);
  printf("\n");
  TestprintBLString(&sub);
}