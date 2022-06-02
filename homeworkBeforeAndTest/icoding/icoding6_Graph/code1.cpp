#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_VERTEX_NUM 50
//顶点为int
typedef int VertexType;

//图的种类：DG 表示有向图, DN 表示有向网, UDG 表示无向图, UDN 表示无向网
typedef enum
{
  DG,
  UDG
} GraphType;

//图的结构
typedef struct
{
  VertexType vertex[MAX_VERTEX_NUM];        //顶点向量
  int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
  int vexnum, arcnum;                       //图的当前顶点数和弧数
  GraphType type;                           //图的种类标志
} MatrixGraph;
int matrix_locate_vertex(MatrixGraph MG, VertexType vex);           //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool matrix_insert_vertex(MatrixGraph G, VertexType v);             //插入顶点v
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w); //在顶点v和w中创建边
int matrix_locate_vertex(MatrixGraph *MG, VertexType vex)           //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
{
  int i = 0;
  for (i = 0; i < MG->vexnum; ++i)
  {
    if (MG->vertex[i] == vex)
      return i;
  }
  return -1;
}
bool matrix_insert_vertex(MatrixGraph *G, VertexType v) //插入顶点v
{
  if (matrix_locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)
  {
    return false;
  }
  G->vertex[G->vexnum] = v;
  G->vexnum++;
  for (int i = 0; i < G->vexnum; ++i)
  {
    G->arcs[i][G->vexnum - 1] = 0;
    G->arcs[G->vexnum - 1][i] = 0;
  }
  return true;
}
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w) //在顶点v和w中创建边
{
  int V = matrix_locate_vertex(G, v);
  int W = matrix_locate_vertex(G, w);
  if (v == -1 || w == -1)
  {
    return false;
  }
  if (G->type == DG)
  {
    if (G->arcs[V][W] == 1)
      return false;
    G->arcs[V][W] = 1;
  }
  else if (G->type == UDG)
  {
    if (G->arcs[V][W] == 1 || G->arcs[W][W] == 1)
      return false;
    G->arcs[V][W] = 1;
    G->arcs[W][V] = 1;
  }
  G->arcnum++;
  return true;
}