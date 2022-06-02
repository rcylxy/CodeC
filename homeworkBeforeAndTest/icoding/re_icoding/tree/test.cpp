#define MAX_CHILDREN_NUM 5
#include "tree.h"
typedef int DataType;

typedef struct Node
{
  DataType data;
  struct Node *left;
  struct Node *right;
} BiTNode, *BiTree;
struct _CSNode
{
  DataType data;
  struct _CSNode *children[MAX_CHILDREN_NUM];
};
typedef struct _CSNode CSNode;

struct __Queue
{
  int i, j; //指向数组内元素的游标
  void **array;
};
typedef struct __Queue Queue;

Queue *create_queue();                   //创建队列
bool is_empty_queue(Queue *tree);        //队为空返回true,不为空时返回false
void *del_queue(Queue *tree);            //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree);
BiTNode *transform(CSNode *root)
{
  if (root == NULL)
    return NULL;
  BiTNode *broot = (BiTNode *)malloc(sizeof(BiTNode));
  broot->data = root->data;
  broot->left = NULL;
  broot->right = NULL;

  Queue *q = create_queue();
  Queue *bq = create_queue();
  BiTree formerNode = NULL;

  add_queue(q, root);
  add_queue(bq, broot);

  while (!is_empty_queue(q))
  {
    CSNode *node = del_queue(q);
    BiTree bTNode = del_queue(bq);
    for (int i = 0; i < MAX_CHILDREN_NUM; ++i)
    {
      if (node->children[i] != NULL)
      {
        BiTree temp = (BiTree)malloc(sizeof(struct Node));
        temp->data = node->children[i]->data;
        temp->left = NULL;
        temp->right = NULL;
        if (i == 0)
        {
          bTNode->left = temp;
        }
        else if (i != 0)
        {
          formerNode->right = temp;
        }
        formerNode = temp;
        add_queue(q, node->children[i]);
        add_queue(bq, temp);
      }
    }
  }
  free_queue(q);
  free_queue(bq);
  return broot;
}