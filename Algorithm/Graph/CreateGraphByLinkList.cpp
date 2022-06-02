#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100
#define MAXSIZE 50

typedef int Status;
typedef int EdgeType;
typedef int VertexType;
typedef int QElemType;

typedef struct EdgeNode {
  int adjvex;
  EdgeType weight;
  struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
  int in;
  VertexType data;
  EdgeNode* firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
  AdjList adjList;
  int numNodes, numEdges;
} GraphAdjList;

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

void printList(AdjList x, int length) {
  printf("\nThe follow is the linklist of the graph:\n");
  EdgeNode* e;
  for (int i = 0; i < length; ++i) {
    e = x[i].firstedge;
    printf("%d-(%d)->", i, e->weight);
    while (e != NULL) {
      if (e->next)
        printf("%d-(%d)->", e->adjvex, e->next->weight);
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
  printf("Please input the vex information!\n");
  for (i = 0; i < G->numNodes; ++i) {
    scanf("%d", &G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }
  printf("Please input the (vi,vj) && its weight and");
  printf("the format is int ,int ,int as a group!\n");
  for (k = 0; k < G->numEdges; ++k) {
    // printf("please input the vi,vj in i.j the format\n");
    // scanf("%d,%d", &i, &j);
    scanf("%d,%d,%d", &i, &j, &w);
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjList[i].firstedge;
    e->weight = w;
    G->adjList[i].firstedge = e;

    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjList[j].firstedge;
    e->weight = w;
    G->adjList[j].firstedge = e;
  }
  printList(G->adjList, G->numNodes);
  printf("Your Creatation is successly achieved!\n");
  return;
}

void initvisited(bool visited[], int length) {
  for (int i = 0; i < length; ++i) {
    visited[i] = false;
  }
}

void DFSbylinklist(GraphAdjList* G, int i, bool (&rvisited)[MAXVEX]) {
  EdgeNode* p;
  rvisited[i] = true;
  printf("%d ", G->adjList[i].data);
  p = G->adjList[i].firstedge;
  while (p) {
    if (!rvisited[p->adjvex])
      DFSbylinklist(G, p->adjvex, rvisited);
    p = p->next;
  }
  return;
}

void BFSbylinklist(GraphAdjList* G, int i, bool (&rvisited)[MAXVEX]) {
  SqQueue Q;
  initQueue(&Q);
  EdgeNode* p;
  for (int k = i; k < G->numNodes; ++k) {
    if (!rvisited[k]) {
      rvisited[k] = true;
      printf("%d ", G->adjList[k].data);
      enQueue(&Q, k);
      while (!isEmptyQueue(&Q)) {
        deQueue(&Q, &k);
        p = G->adjList[k].firstedge;
        while (p) {
          if (!rvisited[p->adjvex]) {
            rvisited[p->adjvex] = true;
            printf("%d ", G->adjList[p->adjvex].data);
            enQueue(&Q, p->adjvex);
          }
          p = p->next;
        }
      }  // while
    }    // if
  }
  return;  // for
}  // func

int main() {
  GraphAdjList G;
  CreateALGraph(&G);
  bool visited[MAXVEX];
  initvisited(visited, MAXVEX);
  bool(&rvisited)[MAXVEX] = visited;
  printf("\nThe DFS list is as follow:\n");
  DFSbylinklist(&G, 0, rvisited);
  initvisited(visited, MAXVEX);
  printf("\n");
  printf("\nThe BFS list is as follow:\n");
  BFSbylinklist(&G, 0, rvisited);
  return 0;
}
/*

9,12 0 1 2 3 4 5 6 7 8
1,2 2,3 2,4 2,5 2,6 3,4 3,7 4,5 5,7 5,8 7,8 8,0

9,12
0 1 2 3 4 5 6 7 8
2,6,7 1,2,1 0,8,11 2,5,2 2,4,3 2,3,4 5,4,5 3,4,6 3,7,7 5,7,8 5,8,9 7,8,10


*/