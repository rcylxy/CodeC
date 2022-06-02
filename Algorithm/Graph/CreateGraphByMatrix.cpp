#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVEX 100
#define GRAPH_INFINITY 65535
#define MAXSIZE 50
#define MAXEDGE 30

typedef int VertexType;
typedef int EdgeType;
typedef int QElemType;
typedef int PatharcOne[MAXVEX];
typedef int ShortPathTableOne[MAXVEX];
typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

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

typedef struct {
  int begin;
  int end;
  int weight;
} Edge;

typedef struct EdgeNode {
  int adjvex;
  int weight;
  struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {
  int in;
  int data;
  EdgeNode* firstEdge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
  AdjList adjList;
  int numEdges, numNodes;
} graphAdjList, *GraphAdjList;

//-------------------------------------------------------------------------queue.h
bool visit(QElemType c);
bool initQueue(SqQueue* Q);
bool clearQueue(SqQueue* Q);
bool isEmptyQueue(SqQueue* Q);
bool isFullQueue(SqQueue* Q);
int queueLength(SqQueue* Q);
bool getHead(SqQueue* Q, QElemType* e);
bool enQueue(SqQueue* Q, QElemType e);
bool deQueue(SqQueue* Q, QElemType* e);
bool traverseQueue(SqQueue* Q);
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------alg.h
void initvisited(bool visited[], int length);
void DFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]);
void BFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]);
void primAlg(MGraph* G);
void swapEdge(Edge* edges, int i, int j);
void sortEdges(Edge edges[], MGraph* G);
int find(int* parent, int f);
void kruskalAlg(MGraph* G);
void dijkstraAlg(MGraph* G, int v0, PatharcOne* P, ShortPathTableOne* D);
void printTwoArray(int X[MAXVEX][MAXVEX], int length);
void floydAlg(MGraph* G, Patharc* P, ShortPathTable* D);
void DFSbylinklist(GraphAdjList G, int i, bool (&rvisited)[MAXVEX]);
void BFSbylinklist(GraphAdjList G, int i, bool (&rvisited)[MAXVEX]);
bool topologicalSort(GraphAdjList G);
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------create.h
void CreateMGraphMap(MGraph* G);
void CreateALGraph(MGraph* G, GraphAdjList* GL);
void printList(AdjList x, int length);
void CreateALGraph(GraphAdjList G);
void printMap(int arc[][MAXVEX], int length);
//-------------------------------------------------------------------------

int main() {
  // 初始化图
  MGraph G;
  CreateMGraphMap(&G);

  // 初始化rvisited
  bool visited[MAXVEX];
  initvisited(visited, MAXVEX);
  bool(&rvisited)[MAXVEX] = visited;

  // DFS测试
  printf("\nThe DFS list is as follow:\n");
  DFS(&G, 0, rvisited);

  // BFS测试
  initvisited(visited, MAXVEX);
  printf("\n");
  printf("\nThe BFS list is as follow:\n");
  BFS(&G, 0, rvisited);

  // Prim算法测试
  printf("\n");
  printf("\nThe min span tree list by prim alg is:\n ");
  primAlg(&G);

  // Kruskal算法测试
  printf("\n");
  kruskalAlg(&G);

  // Dijkstra算法测试
  printf("\n");
  PatharcOne P;
  ShortPathTableOne D;
  int v0 = 0;
  dijkstraAlg(&G, v0, &P, &D);
  printf("\nThis is the shortcut list:\n");
  int j = 0;
  for (int i = 1; i < G.numNodes; ++i) {
    printf("v%d->v%d:\t", v0, i);
    j = i;
    while (P[j] != -1) {
      printf("%d ", P[j]);
      j = P[j];
    }
    printf("\n");
  }
  printf("\nThis is the shortest length of path:\n");
  for (int i = 1; i < G.numNodes; ++i) {
    printf("v%d->v%d: %d\n", v0, i, D[i]);
  }

  // floyd算法测试
  int v, w, k;
  printf("\n\n");
  Patharc P1;
  ShortPathTable D1;
  floydAlg(&G, &P1, &D1);
  for (v = 0; v < G.numNodes; ++v) {
    for (w = v + 1; w < G.numNodes; ++w) {
      printf("v%d->v%d\tweight:%d ", v, w, D1[v][w]);
      k = P1[v][w];
      printf("\tpath: %d", v);
      while (k != w) {
        printf(" -> %d", k);
        k = P1[k][w];
      }
      printf(" -> %d\n", w);
    }
  }
  printf("\nD Matrix:\n");
  printTwoArray(D1, G.numNodes);
  printf("\nP Matrix:\n");
  printTwoArray(P1, G.numNodes);

  //拓扑排序算法测试
  printf("\n\n");
  printf("This is the toposort list && return type:\n");
  GraphAdjList GL;
  CreateALGraph(&G, &GL);
  bool result = topologicalSort(GL);
  printf("\n%d\n", result);

  return 0;
}
/*

9,12
0 1 2 3 4 5 6 7 8
2,6,7 1,2,1 0,8,11 2,5,2 2,4,3 2,3,4 5,4,5 3,4,6 3,7,7 5,7,8 5,8,9 7,8,10

*/

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

/*
对于find函数与parent数组判断是否成环的方法，我有话说：
一般来说，kurskal算法都是建立在无向图之中的，那么我们不妨假设一个边的方向是从下标小的节点过渡到下标大的节点
如何判断最小权值的边i-->j是否会构成环呢？
由离散数学的知识，在一棵生成树中，若是添加任何一条边，都会构成一条基本回路。
那么问题就转换成为了判断i与j节点是否在同样一颗生成树中（也是并查集的问题）
如何判断i和j结点是不是在同一个连通分支里面呢？
find函数出场！
给出一个结论：在任何生成树中都必须至少有2个叶子节点，一定能够找到这样的一个节点使其出度为0！
find函数通过不断地找边，将边的下标从任意值慢慢的变大，最终会找到生成树中下标最大的节点（在刚才假定的前提之下，下标最大的节点的出度一定为0）
因此，我们可以使用find函数的范围值作为一个连通分支的代表
若m!=n，才能保证这两者处于不同的连通分支中，才能将其纳入生成树。
*/
int find(int* parent, int f) {
  while (parent[f] > 0) {
    f = parent[f];
  }
  return f;
}

void kruskalAlg(MGraph* G) {
  int i, j, n, m;
  int k = 0;
  int parent[MAXVEX];
  Edge edges[MAXEDGE];

  for (i = 0; i < G->numNodes; ++i) {
    for (j = i + 1; j < G->numNodes; ++j) {
      if (G->arc[i][j] < GRAPH_INFINITY) {
        edges[k].begin = i;
        edges[k].end = j;
        edges[k].weight = G->arc[i][j];
        k++;
      }
    }
  }
  sortEdges(edges, G);
  printf("\nThe min span tree by Kruskal alg list is as follow:\n");
  for (int i = 0; i < G->numNodes; ++i) {
    parent[i] = 0;
  }
  // 前提是利用了sort函数对边集合进行了对应的排序。
  for (i = 0; i < G->numEdges; ++i) {
    n = find(parent, edges[i].begin);
    m = find(parent, edges[i].end);
    if (m != n) {
      parent[n] = m;
      printf("(%d--w:%d-->%d) ", edges[i].begin, edges[i].weight, edges[i].end);
    }
  }
}

void dijkstraAlg(MGraph* G, int v0, PatharcOne* P, ShortPathTableOne* D) {
  int v, w, k = 0, min;
  int final[MAXVEX];
  for (v = 0; v < G->numNodes; ++v) {
    final[v] = 0;
    (*D)[v] = G->arc[v0][v];
    (*P)[v] = -1;
  }

  (*D)[v0] = 0;
  final[v0] = 1;
  for (v = 1; v < G->numNodes; ++v) {
    min = GRAPH_INFINITY;
    // 下面这个循环就是寻找现在谁离v0最近，把最近的存放在k与min中
    for (w = 0; w < G->numNodes; ++w) {
      if (!final[w] && (*D)[w] < min) {
        k = w;
        min = (*D)[w];
      }
    }
    final[k] = 1;
    // 下面这个循环就是要修正当前的数组，具体的方法是：通过那个节点到新的地方的距离是不是能够更短。
    for (w = 0; w < G->numNodes; ++w) {
      if (!final[w] && (min + G->arc[k][w] < (*D)[w])) {
        (*D)[w] = min + G->arc[k][w];
        (*P)[w] = k;
      }
    }
  }
  return;
}

void printTwoArray(int X[MAXVEX][MAXVEX], int length) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length; ++j) {
      printf("%d\t", X[i][j]);
    }
    printf("\n");
  }
}

void floydAlg(MGraph* G, Patharc* P, ShortPathTable* D) {
  int v, w, k;
  for (v = 0; v < G->numNodes; ++v) {
    for (w = 0; w < G->numNodes; ++w) {
      (*D)[v][w] = G->arc[v][w];
      (*P)[v][w] = w;
    }
  }
  // 喜闻乐见的三层循环
  for (k = 0; k < G->numNodes; ++k) {
    // 遍历所有的节点
    // 遍历所有的短程路径
    for (v = 0; v < G->numNodes; ++v) {
      for (w = 0; w < G->numNodes; ++w) {
        if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
          (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
          (*P)[v][w] = (*P)[v][k];
        }
      }
    }
  }
}

void CreateALGraph(MGraph* G, GraphAdjList* GL) {
  int i, j;
  EdgeNode* e;

  (*GL) = (GraphAdjList)malloc(sizeof(graphAdjList));
  (*GL)->numEdges = G->numEdges;
  (*GL)->numNodes = G->numNodes;

  for (i = 0; i < G->numNodes; ++i) {
    (*GL)->adjList[i].data = G->vexs[i];
    (*GL)->adjList[i].firstEdge = NULL;
    (*GL)->adjList[i].in = 0;
  }
  for (i = 0; i < G->numNodes; ++i) {
    for (j = 0; j < G->numNodes; ++j) {
      if (G->arc[i][j] != 0 && G->arc[i][j] < GRAPH_INFINITY) {
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = (*GL)->adjList[i].firstEdge;
        (*GL)->adjList[i].firstEdge = e;
        (*GL)->adjList[j].in++;
      }
    }
  }
}

bool topologicalSort(GraphAdjList G) {
  EdgeNode* e;
  int i, k, gettop;
  int top = 0;
  int count = 0;
  int* stack;
  stack = (int*)malloc(G->numNodes * sizeof(int));

  for (i = 0; i < G->numNodes; ++i) {
    if (G->adjList[i].in == 0) {
      stack[++top] = i;
    }
  }
  while (top != 0) {
    gettop = stack[top--];
    printf("%d --> ", G->adjList[gettop].data);
    count++;

    for (e = G->adjList[gettop].firstEdge; e; e = e->next) {
      k = e->adjvex;
      --(G->adjList[k].in);
      if (!G->adjList[k].in) {
        stack[++top] = k;
      }
    }
  }
  printf("\n");
  if (count < G->numNodes) {
    return false;
  } else
    return true;
}

void DFSbylinklist(GraphAdjList G, int i, bool (&rvisited)[MAXVEX]) {
  EdgeNode* p;
  rvisited[i] = true;
  printf("%d ", G->adjList[i].data);
  p = G->adjList[i].firstEdge;
  while (p) {
    if (!rvisited[p->adjvex])
      DFSbylinklist(G, p->adjvex, rvisited);
    p = p->next;
  }
  return;
}

void BFSbylinklist(GraphAdjList G, int i, bool (&rvisited)[MAXVEX]) {
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
        p = G->adjList[k].firstEdge;
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

void printList(AdjList x, int length) {
  printf("\nThe follow is the linklist of the graph:\n");
  EdgeNode* e;
  for (int i = 0; i < length; ++i) {
    e = x[i].firstEdge;
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

void CreateALGraph(GraphAdjList G) {
  int i, j, k, w;
  EdgeNode* e;
  printf("Please input your graph's num of vexs and nums of edges! \n");
  scanf("%d,%d", &G->numNodes, &G->numEdges);
  printf("Please input the vex information!\n");
  for (i = 0; i < G->numNodes; ++i) {
    scanf("%d", &G->adjList[i].data);
    G->adjList[i].firstEdge = NULL;
  }
  printf("Please input the (vi,vj) && its weight and");
  printf("the format is int ,int ,int as a group!\n");
  for (k = 0; k < G->numEdges; ++k) {
    // printf("please input the vi,vj in i.j the format\n");
    // scanf("%d,%d", &i, &j);
    scanf("%d,%d,%d", &i, &j, &w);
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjList[i].firstEdge;
    e->weight = w;
    G->adjList[i].firstEdge = e;

    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjList[j].firstEdge;
    e->weight = w;
    G->adjList[j].firstEdge = e;
  }
  printList(G->adjList, G->numNodes);
  printf("Your Creatation is successly achieved!\n");
  return;
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
      if (i == j)
        G->arc[i][j] = 0;
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

void initvisited(bool visited[], int length) {
  for (int i = 0; i < length; ++i) {
    visited[i] = false;
  }
}

void DFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]) {
  rvisited[i] = true;
  int j = 0;
  printf("%d ", G->vexs[i]);
  for (j = 0; j < G->numNodes; ++j) {
    if (G->arc[i][j] != GRAPH_INFINITY && G->arc[i][j] != 0 && !rvisited[j])
      DFS(G, j, rvisited);
  }
}

void BFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]) {
  SqQueue Q;
  initQueue(&Q);
  for (int k = i; k < G->numNodes; ++k) {
    if (!rvisited[k]) {
      rvisited[k] = true;
      printf("%d ", G->vexs[k]);
      enQueue(&Q, k);
      while (!isEmptyQueue(&Q)) {
        deQueue(&Q, &k);
        for (int j = 0; j < G->numNodes; ++j) {
          if (G->arc[k][j] != GRAPH_INFINITY && G->arc[k][j] != 0 &&
              !rvisited[j]) {
            rvisited[j] = true;
            printf("%d ", G->vexs[j]);
            enQueue(&Q, j);
          }  // if
        }    // for
      }      // while
    }        // if
  }          // for
}  // func

void primAlg(MGraph* G) {
  int min, i, j, k = 0;
  int adjvex[MAXVEX];
  int lowcost[MAXVEX];
  lowcost[0] = 0;
  // lowcost数组元素为0代表着已经被加入了最小生成树，代价为0了
  adjvex[0] = 0;
  // 存储是谁到的这个节点
  for (i = 1; i < G->numNodes; ++i) {
    lowcost[i] = G->arc[0][i];
    adjvex[i] = 0;
  }
  for (i = 1; i < G->numNodes; ++i) {
    min = GRAPH_INFINITY;
    j = 1;
    k = 0;
    while (j < G->numNodes) {
      // 遍历所有没有被加入到最小生成树的节点，找到目前最小的边
      if (lowcost[j] != 0 && lowcost[j] < min) {
        min = lowcost[j];
        k = j;
      }
      j++;
    }
    // 加入最小的边在生成树中
    // 打印最小生成树
    printf("(%d--w:%d-->%d) ", adjvex[k], G->arc[adjvex[k]][k], k);
    // 把已经找到的最小权值的边放进生成树中
    lowcost[k] = 0;
    // 因为将k节点加入了生成树，最小权值的边会发生变化，遍历所有边更新所有最小代价的值
    for (j = 1; j < G->numNodes; ++j) {
      if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j]) {
        lowcost[j] = G->arc[k][j];
        adjvex[j] = k;
      }
    }
  }
}

void swapEdge(Edge* edges, int i, int j) {
  int temp = 0;
  temp = edges[i].begin;
  edges[i].begin = edges[j].end;
  edges[j].end = temp;

  temp = edges[i].end;
  edges[i].end = edges[j].end;
  edges[j].end = temp;

  temp = edges[i].weight;
  edges[i].weight = edges[j].weight;
  edges[j].weight = temp;
}

void sortEdges(Edge edges[], MGraph* G) {
  for (int i = 0; i < G->numEdges; ++i) {
    for (int j = i + 1; j < G->numEdges; ++j) {
      if (edges[i].weight > edges[j].weight) {
        swapEdge(edges, i, j);
      }
    }
  }
  printf("\nThe list sorted by weight as follow:\n");
  for (int i = 0; i < G->numEdges; i++) {
    printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
  }
}
