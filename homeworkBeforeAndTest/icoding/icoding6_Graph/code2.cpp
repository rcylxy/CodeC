#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_VERTEX_NUM 50
//顶点为int
typedef int VertexType; //顶点为int
typedef int InfoPtr;
//图的种类：DG 表示有向图, DN 表示有向网, UDG 表g示无向图, UDN 表示无向网
typedef enum
{
  DG,
  UDG
} GraphType;

//弧结构
typedef struct ArcNode
{
  int adjvex; /*该弧指向顶点的位置*/
  InfoPtr *info;
  struct ArcNode *nextarc; /*指向下一条弧的指针*/
} ArcNode;

typedef struct VNode
{
  VertexType data;   /*顶点数据*/
  ArcNode *firstarc; /*指向该顶点第一条弧的指针*/
} VNode;

typedef struct
{
  VNode vertex[MAX_VERTEX_NUM];
  int vexnum, arcnum; /*图的顶点数和弧数*/
  GraphType type;     /*图的种类标志*/
} ListGraph;          /*基于邻接表的图*/

int locate_vertex(ListGraph *G, VertexType v) //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
{
  int i = 0;
  for (i = 0; i < G->vexnum; ++i)
  {
    if (G->vertex[i].data == v)
      return i;
  }
  return -1;
}
bool insert_vertex(ListGraph *G, VertexType v)
{
  if (locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)
    return false;
  G->vertex[G->vexnum].data = v;
  G->vertex[G->vexnum].firstarc = NULL;
  G->vexnum++;
  return true;
}
bool insert_arc(ListGraph *G, VertexType v, VertexType w)
{
  if (locate_vertex(G, v) == -1 || locate_vertex(G, w) == -1)
    return false;

  int V = locate_vertex(G, v);
  int W = locate_vertex(G, w);
  if (G->type == DG)
  {
    ArcNode *p = G->vertex[V].firstarc;
    ArcNode *NewNodeV = (ArcNode *)malloc(sizeof(struct ArcNode));
    while (p->nextarc != NULL)
    {
      p = p->nextarc;
    }
    p->nextarc = NewNodeV;
    NewNodeV->adjvex = w;
    NewNodeV->nextarc = NULL;
    G->arcnum++;
  }
  else
  {
    ArcNode *p = G->vertex[V].firstarc;
    ArcNode *q = G->vertex[W].firstarc;
    ArcNode *NewNodeV = (ArcNode *)malloc(sizeof(struct ArcNode));
    ArcNode *NewNodeW = (ArcNode *)malloc(sizeof(struct ArcNode));
    while (p->nextarc != NULL)
    {
      p = p->nextarc;
    }
    while (q->nextarc != NULL)
    {
      q = q->nextarc;
    }
    NewNodeV->adjvex = w;
    NewNodeV->nextarc = NULL;
    p->nextarc = NewNodeV;

    NewNodeV->adjvex = w;
    NewNodeV->nextarc = NULL;
    q->nextarc = NewNodeV;

    G->arcnum += 2;
  }
  return true;
}