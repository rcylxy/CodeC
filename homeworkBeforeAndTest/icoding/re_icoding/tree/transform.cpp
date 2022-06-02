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
void free_queue(Queue *tree);            //释放队列
BiTNode *transform(CSNode *root)
{
  BiTNode *r = (BiTNode *)malloc(sizeof(BiTNode));
  BiTNode *s = (BiTNode *)malloc(sizeof(BiTNode));
  Queue *q;
  q = create_queue();
  add_queue(q, root);
  r->data = root->data;
  BiTNode *ret = r;
  q->i = q->j = 0;

  while (!is_empty_queue(q))
  {
    CSNode *temp = (CSNode *)del_queue(q);
    r->data = temp->data;

    s = (BiTNode *)malloc(sizeof(BiTNode));
    q->i++;
    s->data = temp->data;
    r->left = s;

    for (int cnt = 0; temp->children[cnt] != NULL; ++cnt)
    {
      add_queue(q, temp->children[cnt]);
      q->j++;
    }
    for (int cnt = q->i; cnt <= q->j; ++cnt)
    {
      s = (BiTNode *)malloc(sizeof(BiTNode));
      s->data = q->array[cnt]->data;
      r->right =
    }
  }
  return ret;
}

BiTNode *transform(CSNode *root)
{
  if (root == NULL)
    return NULL;
  BiTree broot = (BiTree)malloc(sizeof(struct Node));
  broot->data = root->data;
  broot->left = broot->right = NULL;
  Queue *q = create_queue();
  Queue *bq = create_queue();
  add_queue(q, root);
  add_queue(bq, broot);

  while (!is_empty_queue(q))
  {
    //从普通数和二叉树中分别取出一个结点
    CSNode *node = del_queue(q);
    BiTree bTreeNode = del_queue(bq);

    int i;
    BiTree formerNode = NULL;
    //遍历普通树结点的所有孩子结点，将孩子加入队列
    for (i = 0; i < MAX_CHILDREN_NUM; i++)
    {
      //孩子非空
      if (node->children[i])
      {
        //二叉树节点初始化并赋值
        BiTree bnode = (BiTree)malloc(sizeof(struct Node));
        bnode->left = bnode->right = NULL;
        bnode->data = node->children[i]->data;

        if (i == 0) //普通树的第一个孩子作为二叉树的左孩子
        {
          bTreeNode->left = bnode;
        }

        else //后面的孩子结点作为前面结点的右孩子
        {
          formerNode->right = bnode;
        }
        formerNode = bnode;

        add_queue(q, node->children[i]);
        add_queue(bq, bnode);
      }
    }
  }
  free(q->array);
  free(q);
  free(bq->array);
  free(bq);
  return broot;
}