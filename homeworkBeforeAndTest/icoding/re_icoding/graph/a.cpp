#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 50
#define InfoPtr int
typedef int VertexType;

typedef enum
{
  DG,
  UDG
} GraphType;

typedef struct ArcNode
{
  int adjvex;
  InfoPtr *info;
  struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
  VertexType data;
  ArcNode *firstarc;
} VNode;
typedef struct
{
  VNode vertex[MAX_VERTEX_NUM];
  int vexnum, arcnum;
  GraphType type;
} ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v);   //删除顶点 v
bool del_vertex(ListGraph *G, VertexType v)
{
  int V = locate_vertex(G, v);
  if (V == -1)
    return false;
  ArcNode *p = G->vertex[V].firstarc;
  ArcNode *q, *pNode;
  //删除所有的以V开头的边
  while (p)
  {
    q = p->nextarc;
    free(p);
    p = q;
    G->arcnum--;
  }
  free(G->vertex[V].firstarc);
  G->arcnum--;
  G->vexnum--;
  //删除这个节点，就是把后面的往前面移动
  for (int i = V; i < G->vexnum; ++i)
  {
    G->vertex[i] = G->vertex[i + 1];
  }
  G->vexnum--;
  //删除所有以其为终点的弧
  for (int i = 0; i < G->vexnum; ++i)
  {
    p = G->vertex[i].firstarc, pNode = NULL;
    while (p)
    {
      if (p->adjvex == V)
      { // P的下个结点是V
        if (!pNode)
        { // P是表头结点
          q = G->vertex[i].firstarc;
          G->vertex[i].firstarc = p->nextarc;
        }
        else
        {
          pNode->nextarc = p->nextarc;
          q = p;
        }
        p = p->nextarc;
        free(q);
        G->arcnum--;
      }
      else
      {
        pNode = p;
        p = p->nextarc;
      }
    }
  }
  return true;
}