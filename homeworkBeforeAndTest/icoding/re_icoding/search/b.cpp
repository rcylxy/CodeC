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
  int hash = hash_string(key) % table->size;
  HashEntry *p = table->bucket[hash];
  if (!p)
  {
    p = (HashEntry *)malloc(sizeof(HashEntry));
    if (!p)
      return HASH_ERROR;
    p->key.str_value = (char *)malloc(sizeof(char) * strlen(key));
    strcpy(p->key.str_value, key);
    p->value.int_value = value;
    p->next = NULL;
    table->bucket[hash] = p;
    return HASH_ADDED;
  }
  p = table->bucket[hash];
  while (p)
  {
    if (strcmp(p->key.str_value, key) == 0)
    {
      if (p->value.int_value == value)
      {
        return HASH_ALREADY_ADDED;
      }
      else if (p->value.int_value != value)
      {
        p->value.int_value = value;
        return HASH_REPLACED_VALUE;
      }
    }
    else
    {
      if (p->next)
        p = p->next;
      else
        break;
    }
  }
  HashEntry *q = (HashEntry *)malloc(sizeof(HashEntry));
  if (!q)
    return HASH_ERROR;
  q->key.str_value = (char *)malloc(sizeof(char) * strlen(key));
  if (!q->key.str_value)
  {
    free(q);
    return HASH_ERROR;
  }
  strcpy(q->key.str_value, key);
  q->value.int_value = value;

  p->next = q;
  q->next = NULL;
  return HASH_ADDED;
}