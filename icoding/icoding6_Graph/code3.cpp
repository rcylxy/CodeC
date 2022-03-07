#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef int InfoPtr;
#define MAX_VERTEX_NUM 50
//顶点为int
typedef int VertexType;

//图的种类：DG 表示有向图, DN 表示有向网, UDG 表示无向图, UDN 表示无向网
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

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v);
bool insert_vertex(ListGraph *G, VertexType v)
{
  if (locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)
    return false;
  G->vertex[G->vexnum].data = v;
  G->vertex[G->vexnum].firstarc = NULL;
  G->vexnum++;
  return true;
}
bool del_vertex(ListGraph *G, VertexType v)
{
  int V = locate_vertex(G, v);
  if (V == -1)
    return false;
  while (G->vertex[V].firstarc)
  {
    ArcNode *p = G->vertex[V].firstarc;
    if (p->nextarc)
    {
      ArcNode *temp = p->nextarc;
      p->nextarc = temp->nextarc;
      free(temp);
    }
    else
    {
      free(p);
      G->vertex[V].firstarc = NULL;
    }
    G->arcnum--;
  }
  G->vexnum--;
  int i;
  for (i = V; i < G->vexnum; ++i)
  {
    G->vertex[i] = G->vertex[i + 1];
  }
  for (int i = 0; i < G->vexnum; ++i)
  {
    ArcNode *P = G->vertex[i].firstarc, *pNode = NULL;
    ArcNode *temp;
    while (P)
    {
      if (P->adjvex != V)
      {
        pNode = P;
        P = P->nextarc;
      }
      else if (P->adjvex == V)
      {
        if (pNode == NULL)
        {
          temp = G->vertex[V].firstarc;
          G->vertex[V].firstarc = temp->nextarc;
        }
        else if (pNode != NULL)
        {
          pNode->nextarc = P->nextarc;
          temp = P;
        }
        P = P->nextarc;
        free(temp);
        G->arcnum--;
      }
    }
  }
  return true;
}