#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <iostream>

#define TRUE 0
#define FALSE 0
#define MAXVEX 100
#define GRAPH_INFINITY 65535
#define MAXSIZE 50

typedef int VertexType;
typedef int EdgeType;
typedef int QElemType;

typedef struct {
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numNodes, numEdges;
} MGraph;

typedef struct {
  QElemType data[MAXSIZE];
  int rear;
  int front;
} SqQueue;

bool visit(QElemType c) {
  printf("%d ", c);
  return true;
}

bool initQueue(SqQueue* Q) {
  Q->rear = 0;
  Q->front = 0;
  return true;
}

bool clearQueue(SqQueue* Q) {
  Q->rear = 0;
  Q->front = 0;
  return true;
}

bool isEmptyQueue(SqQueue* Q) {
  return (Q->rear == Q->front);
}

bool isFullQueue(SqQueue* Q) {
  return ((Q->rear + 1) % MAXSIZE == Q->front);
}

int queueLength(SqQueue* Q) {
  return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

bool getHead(SqQueue* Q, QElemType* e) {
  if (isEmptyQueue(Q)) {
    return false;
  }
  *e = Q->data[Q->front];
  return true;
}

bool enQueue(SqQueue* Q, QElemType e) {
  if (isFullQueue(Q))
    return false;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return true;
}

bool deQueue(SqQueue* Q, QElemType* e) {
  if (isEmptyQueue(Q))
    return false;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return true;
}

bool traverseQueue(SqQueue* Q) {
  int i = Q->front;
  while (i != Q->rear) {
    visit(Q->data[i]);
    i = (i + 1) % MAXSIZE;
  }
  return true;
}

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
  printf("Please input the vex information!\n");
  for (i = 0; i < G->numNodes; ++i) {
    scanf("%d", &G->vexs[i]);
  }
  for (i = 0; i < G->numNodes; ++i) {
    for (j = 0; j < G->numNodes; ++j) {
      G->arc[i][j] = GRAPH_INFINITY;
    }
  }
  printf("Please input the (vi,vj) && its weight and");
  printf("the format is int ,int ,int as a group!\n");
  for (k = 0; k < G->numEdges; ++k) {
    scanf("%d,%d,%d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = w;  // that's the only one in the non-direction graph
  }
  printMap(G->arc, G->numNodes);
  printf("Your Creatation is successly achieved!\n");
  return;
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

void BFS() {}

int main() {
  MGraph G;
  CreateMGraphMap(&G);
  bool visited[MAXVEX];
  bool(&rvisited)[MAXVEX] = visited;
  printf("\nThe DFS list is as follow:\n");
  DFS(&G, 0, rvisited);
  return 0;
}
/*
9,12
0 1 2 3 4 5 6 7 8
2,6,7 1,2,1 0,8,11 2,5,2 2,4,3 2,3,4 5,4,5 3,4,6 3,7,7 5,7,8 5,8,9 7,8,10
*/
