#include "D:\homework\git\CodeC\programTest1\include\matrixGraph.h"
#include <stdio.h>
#include <stdlib.h>

void printMap(int arc[][MAXVEX], int length) {
  printf("\nThe follow is the map of the graph:\n");
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

void CreateMGraphMap(MGraph* G) {
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
  printf("success\n");
}

void DFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]) {
  rvisited[i] = true;
  int j = 0;
  printf("%d ", G->vexs[i]);
  for (j = 0; j < G->numNodes; ++j) {
    if (G->arc[i][j] != GRAPH_INFINITY && !rvisited[j])
      DFS(G, j, rvisited);
  }
}
