#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROE 0
#define TRUE 0
#define FALSE 0
#define MAXVEX 100
#define GRAPH_INFINITY 65535

// enum Status { OK, ERROR, TRUE, FALSE };
typedef int Status;
typedef int VertexType;
typedef int EdgeType;

typedef struct {
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numNodes, numEdges;
} MGraph;

void printMap(int arc[][MAXVEX], int length) {
  printf("\t");
  for (int i = 0; i < length; ++i) {
    printf("%d\t", i);
  }
  printf("\n");
  for (int i = 0; i < length; ++i) {
    printf("%d\t", i);
    for (int j = 0; j < length; ++j) {
      if (arc[i][j] != GRAPH_INFINITY) {
        printf("%d\t", arc[i][j]);
      } else {
        printf("INF\t");
      }
    }
    printf("\n");
  }
}

void CreateMGraph(MGraph* G) {
  int i, j, k, w;
  printf("Please input your graph's num of vexs and nums of edges! \n");
  scanf("%d,%d", &G->numNodes, &G->numEdges);
  printf("input the vex information\n");
  for (i = 0; i < G->numNodes; ++i) {
    scanf("%d", &G->vexs[i]);
  }
  for (i = 0; i < G->numNodes; ++i) {
    for (j = 0; j < G->numNodes; ++j) {
      G->arc[i][j] = GRAPH_INFINITY;
    }
  }
  printf("Please input the (vi,vj) && its weight\n");
  printf("the format is (int ,int ,int) as a group\n");
  for (k = 0; k < G->numEdges; ++k) {
    scanf("%d,%d,%d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = w;  // that's the only one in the non-direction graph
  }
  printMap(G->arc, G->numNodes);
}

int main() {
  MGraph G;
  CreateMGraph(&G);
  printf("success\n");
  return 0;
}
/*

9,11 0 1 2 3 4 5 6 7 8 9 10
1,2,1 0,8,11 2,5,2 2,4,3 2,3,4 5,4,5 3,4,6 3,7,7 5,7,8 5,8,9 7,8,10

*/
