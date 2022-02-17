#define scanf_s scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
typedef int ElemType;
typedef struct SqList
{
  ElemType *elem;
  int length;
  int list_size;
} SqList, *Ptr, *SqListPtr;
enum Status
{
  success,
  fail,
  fetal,
  range_error
};
Status List_Init(SqListPtr L);
void List_Destory(SqListPtr L);
void List_clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *p);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType *elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);
void List_Print(SqListPtr L);
Status Test_CreateList(SqListPtr list, ElemType data[], int n);
Status Test_ClearList(SqListPtr list);
Status Test_RetrvialPriorNext(SqListPtr list, int pos);
Status Test_Locate(SqListPtr list, ElemType e);
void Test_Size(SqListPtr list);
void del_dupnum(SqListPtr L);

int main()
{
  int opt = 1;
  SqList list;
  int pos, size, i;
  ElemType e, *data;
  Status s;
  printf("请输入选项:\n");
  printf("1.测试建立线性表\n");
  printf("2.测试清空线性表\n");
  printf("3.测试求某位置元素的值的前驱与后继\n");
  printf("4.测试查询某元素的位置\n");
  printf("5.测试线性表的长度\n");
  printf("6.结束查询\n");
  printf("7.删除重复元素\n");
  while (opt != 6)
  {

    scanf_s("%d", &opt);
    switch (opt)
    {
    case 1:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      if (s != success)
        printf("建立线性表失败\n");
      free(data);
      List_Destory(&list);
      break;
    case 2:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      if (s == success)
      {
        if (!List_Empty(&list))
        {
          List_clear(&list);
          if (List_Empty(&list))
          {
            printf("清空完成\n");
          }
        }
      }
      free(data);
      List_Destory(&list);
      break;
    case 3:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      if (s == success)
      {
        printf("输入待查找的位置：\n");
        scanf_s("%d", &pos);
        Test_RetrvialPriorNext(&list, pos);
      }
      free(data);
      List_Destory(&list);
      break;
    case 4:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      if (s == success)
      {
        printf("输入待查询元素的值：\n");
        scanf_s("%d", &e);
        Test_Locate(&list, e);
      }
      free(data);
      List_Destory(&list);
      break;
    case 5:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      if (s == success)
      {
        Test_Size(&list);
      }
      free(data);
      List_Destory(&list);
      break;
    case 7:
      printf("线性表长度：\n");
      scanf_s("%d", &size);
      data = (ElemType *)malloc((size + 1) * sizeof(ElemType));
      if (data == NULL)
        break;
      printf("线性表元素：\n");
      for (i = 1; i <= size; ++i)
      {
        scanf_s("%d", &data[i]);
      }
      s = Test_CreateList(&list, data, size);
      printf("\n");
      del_dupnum(&list);
      List_Print(&list);
      break;

    default:
      break;
    }
    printf("\n请输入选项:\n");
    printf("1.测试建立线性表\n");
    printf("2.测试清空线性表\n");
    printf("3.测试求某位置元素的值的前驱与后继\n");
    printf("4.测试查询某元素的位置\n");
    printf("5.测试线性表的长度\n");
    printf("6.结束查询\n");
    printf("7.删除重复元素\n");
  }

  return 0;
}

Status List_Init(SqListPtr L)
{
  Status s = fail;
  if (L != NULL)
  {
    L->elem = (ElemType *)malloc((LIST_INIT_SIZE + 1) * sizeof(ElemType));
    if (L->elem)
    {
      L->list_size = LIST_INIT_SIZE;
      L->length = 0;
      s = success;
    }
  }
  return s;
}
void List_Destory(SqListPtr L)
{
  if (L)
  {
    if (L->elem)
    {
      free(L->elem);
      L->elem = NULL;
      L->length = 0;
    }
  }
}
void List_clear(SqListPtr L)
{
  L->length = 0;
}
bool List_Empty(SqListPtr L)
{
  return (L->length == 0);
}
int List_size(SqListPtr L)
{
  return L->length;
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
  Status s = range_error;
  if (L)
  {
    if (pos >= 1 && pos <= L->length)
    {
      *elem = L->elem[pos];
      s = success;
    }
  }
  return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
  Status s = range_error;
  int i = 1;
  if (L)
  {
    for (i = 1; i <= L->length; ++i)
    {
      if (L->elem[i] == elem)
      {
        *pos = i;
        s = success;
        break;
      }
    }
  }
  return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
  Status s = range_error;
  int i;
  if (L)
  {
    if (pos >= 1 && pos <= L->length + 1)
    {
      if (L->length < L->list_size)
      {
        for (i = L->length; i >= pos; --i)
        {
          L->elem[i + 1] = L->elem[i];
        }
        L->elem[i + 1] = elem;
        L->length++;
        s = success;
      }
    }
  }
  return s;
}
Status List_delete(SqListPtr L, int pos)
{
  Status s = range_error;
  int i;
  if (L)
  {
    if (pos >= 1 && pos <= L->length + 1)
    {
      for (i = pos + 1; i <= L->length; ++i)
      {
        L->elem[i - 1] = L->elem[i];
      }
      L->length--;
      s = success;
    }
  }
  return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
  Status s = range_error;
  if (L)
  {
    if (pos > 1 && pos <= L->length)
    {
      *elem = L->elem[pos - 1];
      s = success;
    }
  }
  return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
  Status s = range_error;
  if (L)
  {
    if (pos >= 1 && pos < L->length)
    {
      *elem = L->elem[pos + 1];
      s = success;
    }
  }
  return s;
}
void List_Print(SqListPtr L)
{
  int i;
  if (L)
  {
    for (i = 1; i <= L->length; ++i)
    {
      printf("%d ", L->elem[i]);
      if (i % 10 == 0)
      {
        printf("\n");
      }
    }
  }
}
Status Test_CreateList(SqListPtr list, ElemType data[], int n)
{
  int i;
  Status s = fail;
  s = List_Init(list);
  if (s == success)
  {
    for (i = 1; i <= n; ++i)
    {
      s = List_Insert(list, i, data[i]);
      if (s != success)
      {
        break;
      }
    }
    List_Print(list);
  }
  return s;
}
Status Test_ClearList(SqListPtr list)
{
  Status s = fail;
  if (!List_Empty(list))
  {
    List_clear(list);
    if (List_Empty(list))
    {
      s = success;
    }
  }
  return s;
}
Status Test_RetrvialPriorNext(SqListPtr list, int pos)
{
  Status s = range_error;
  ElemType e;
  s = List_Retrival(list, pos, &e);
  if (s == success)
  {
    printf("%d的元素是%d", pos, e);
    s = List_Prior(list, pos, &e);
    if (s == success)
    {
      printf("%d元素的直接前驱是%d", pos, e);
    }
    else
      printf("元素的直接前驱是不存在的\n");

    s = List_Next(list, pos, &e);
    if (s == success)
    {
      printf("%d元素的直接后继是%d", pos, e);
    }
    else
      printf("元素的直接后继是不存在的\n");
  }
  return s;
}
Status Test_Locate(SqListPtr list, ElemType e)
{
  Status s;
  int pos;
  s = List_Locate(list, e, &pos);
  if (s == success)
  {
    printf("%d的位置是%d", e, pos);
  }
  else
    printf("查找失败\n");
  return s;
}
void Test_Size(SqListPtr list)
{
  int len;
  len = List_size(list);
  printf("线性表的长度是%d\n", len);
}
void del_dupnum(SqListPtr L)
{
  int i, j;
  i = j = 0;
  for (i = 0; i <= L->length; i++)
  {
    // i往前走，j滞后一点，如果遇到相同的数j就不走，直到有不同的数放入j位置
    if (L->elem[j] != L->elem[i])
    {
      j++;
      L->elem[j] = L->elem[i];
    }
  }
  (L->length) = j - 1; //此处的j就是末尾下标
}
