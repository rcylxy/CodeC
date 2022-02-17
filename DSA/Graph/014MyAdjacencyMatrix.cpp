#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define OK 1
#define ERROR 0
typedef int Status;
#define MAXVEX 100
#define GRAPH_INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
  VertexType vexs[MAXVEX];
  EdgeType arcs[MAXVEX][MAXVEX];
  int numNodes, numEdges;
} MGraph;

void CreateMGraph(MGraph *G)
{
  int i, j, k, w;
  printf("输入顶点数与边数\n");
  scanf("%d,%d", &(G->numNodes), &(G->numEdges));
  for (i = 0; i < G->numNodes; ++i)
    scanf("%c", &G->vexs[i]);
  for (i = 0; i < G->numNodes; ++i)
    for (j = 0; j < G->numNodes; ++j)
      G->arcs[i][j] = GRAPH_INFINITY;
  for (k = 0; k < G->numEdges; ++k)
  {
    printf("输入边(vi,vj)的下标i，下标j和权值w：\n");
    scanf("%d,%d,%d", &i, &j, &w);
    G->arcs[i][j] = w;
    G->arcs[j][i] = G->arcs[i][j];
  }
}
int main(int argc, char *argv[])
{
  MGraph G;
  CreateMGraph(&G);
  return 0;
}