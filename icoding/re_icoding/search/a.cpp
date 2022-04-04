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
// 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
HASH_RESULT hash_add_int(HashTable *table, const char *key, int value)
{
  long weizhi = hash_string(key);
  HashEntry *h = table->bucket[weizhi];
  if (h)
  {
    if (h->value.int_value != value)
    {
      h->value.int_value = value;
      return HASH_REPLACED_VALUE;
    }
    else if (h->value.int_value == value)
    {
      return HASH_ALREADY_ADDED;
    }
  }
  else if (!h)
  {
    h = (HashEntry *)malloc(sizeof(HashEntry));
    if (!h)
    {
      return HASH_ERROR;
    }
    else if (h)
    {
      h->key.str_value = (char *)malloc(sizeof(char) * 500);
      strcpy(h->key.str_value, key);
      h->value.int_value = value;
      return HASH_ADDED;
    }
  }
}

HASH_RESULT hash_add_int(HashTable *table, const char *key, int value)
{
  long weizhi = hash_string(key);
  HashEntry *p = table->bucket[weizhi];
  for (p = table->bucket[weizhi]; p && strcmp(p->key.str_value, key);)
    p = p->next;
  if (p)
  {
    if (value == p->value.int_value)
      return HASH_ALREADY_ADDED;
    else
    {
      p->value.int_value = value;
      return HASH_REPLACED_VALUE;
    }
  }
  p = (HashEntry *)malloc(sizeof(HashEntry));
  if (!p)
    return HASH_ERROR;
  else
  {
    p->key.str_value = (char *)malloc(200 * sizeof(char));
    if (!p->key.str_value)
      return HASH_ERROR;
  }
  strcpy(p->key.str_value, key);
  p->value.int_value = value;
  table->bucket[weizhi] = p; //这里按道理应该把之前的节点接到p的next域上
  return HASH_ADDED;
}