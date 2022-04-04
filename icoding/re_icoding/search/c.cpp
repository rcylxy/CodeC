#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
  HASH_OK,
  HASH_ERROR,
  HASH_ADDED,
  HASH_REPLACED_VALUE,
  HASH_ALREADY_ADDED,
  HASH_DELETED,
  HASH_NOT_FOUND,
} HASH_RESULT;

typedef struct __HashEntry HashEntry;
struct __HashEntry
{
  union
  {
    char *str_value;
    double dbl_value;
    int int_value;
  } key;
  union
  {
    char *str_value;
    double dbl_value;
    int int_value;
    long long_value;
    void *ptr_value;
  } value;
  HashEntry *next;
};

struct __HashTable
{
  HashEntry **bucket;
  int size;
  HASH_RESULT last_error;
};
typedef struct __HashTable HashTable;
long hash_string(const char *str)
{
  long hash = 5381;
  int c;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  if (hash < 0)
    hash *= -1;
  return hash;
}
HASH_RESULT hash_add_int(HashTable *table, const char *key, int value)
{

  HashEntry *p;                           //指的是每一个键值对
  int h = hash_string(key) % table->size; //保存哈希函数返回值
  // int类型也可以
  //  !h %= table->size; 编译器奇怪的不通过.....

  //该关键字对应的哈希表中键值对不存在, 分配节点存入
  if (!table->bucket[h])
  {
    p = (HashEntry *)malloc(sizeof(HashEntry));
    if (!p)
      return HASH_ERROR;
    p->key.str_value = (char *)malloc(strlen(key));
    if (!p->key.str_value)
    {
      free(p);
      return HASH_ERROR;
    }
    //!!!!字符串拷贝
    strcpy(p->key.str_value, key);
    p->value.int_value = value;
    //最好还是置空
    p->next = NULL;
    table->bucket[h] = p;

    return HASH_ADDED;
  }

  //关键字对应的哈希表中该位置存在键值对,判断重复或者冲突
  p = table->bucket[h];
  while (p)
  {

    //关键字相同
    if (strcmp(key, p->key.str_value) == 0)
    {
      //判断值
      if (p->value.int_value == value)
      {
        return HASH_ALREADY_ADDED;
      }
      else
      {
        p->value.int_value = value;
        return HASH_REPLACED_VALUE;
      }
    }
    //链地址法
    else
    {
      if (p->next)
        p = p->next;
      else
        break;
    }
  }
  //循环完成后
  // p指向最后一个结点
  HashEntry *q; // q接到p后面
  q = (HashEntry *)malloc(sizeof(HashEntry));
  if (!q)
    return HASH_ERROR;

  q->key.str_value = (char *)malloc(strlen(key));
  if (!q->key.str_value)
  {
    free(q);
    return HASH_ERROR;
  }

  strcpy(q->key.str_value, key);
  q->value.int_value = value;
  q->next = NULL;
  p->next = q;

  return HASH_ADDED;
}