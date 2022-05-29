#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100

typedef int Status;
typedef int EdgeType;
typedef int VertexType;

typedef struct EdgeNode {
  int adjvex;
  EdgeType Info;
  struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
  VertexType data;
  EdgeNode* firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
  AdjList adjlist;
  int numNodes, numEdges;
} GraphAdjList;

void printList(AdjList x, int length) {
  printf("\nThe follow is the linklist of the graph:\n");
  EdgeNode* e;
  for (int i = 0; i < length; ++i) {
    e = x[i].firstedge;
    printf("%d-(%d)->", i, e->Info);
    while (e != NULL) {
      if (e->next)
        printf("%d-(%d)->", e->adjvex, e->next->Info);
      else
        printf("%d", e->adjvex);
      e = e->next;
    }
    printf("\n");
  }
}

void CreateALGraph(GraphAdjList* G) {
  int i, j, k, w;
  EdgeNode* e;
  printf("Please input your graph's num of vexs and nums of edges! \n");
  scanf("%d,%d", &G->numNodes, &G->numEdges);
  for (i = 0; i < G->numNodes; ++i) {
    scanf("%d", &G->adjlist[i].data);
    G->adjlist[i].firstedge = NULL;
  }

  for (k = 0; k < G->numEdges; ++k) {
    // printf("please input the vi,vj in i.j the format\n");
    // scanf("%d,%d", &i, &j);
    scanf("%d,%d,%d", &i, &j, &w);
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjlist[i].firstedge;
    e->Info = w;
    G->adjlist[i].firstedge = e;

    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjlist[j].firstedge;
    e->Info = w;
    G->adjlist[j].firstedge = e;
  }
  printList(G->adjlist, G->numNodes);
}

int main() {
  GraphAdjList G;
  CreateALGraph(&G);
  printf("success\n");

  return 0;
}
/*

9,12 0 1 2 3 4 5 6 7 8
1,2 2,3 2,4 2,5 2,6 3,4 3,7 4,5 5,7 5,8 7,8 8,0

9,12 0 1 2 3 4 5 6 7 8
2,6,7 1,2,1 0,8,11 2,5,2 2,4,3 2,3,4 5,4,5 3,4,6 3,7,7 5,7,8 5,8,9 7,8,10


*/