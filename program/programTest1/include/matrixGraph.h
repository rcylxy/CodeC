#define TRUE 0
#define FALSE 0
#define MAXVEX 100
#define GRAPH_INFINITY 65535
typedef int VertexType;
typedef int EdgeType;

typedef struct {
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numNodes, numEdges;
} MGraph;
void printMap(int arc[][MAXVEX], int length);
void CreateMGraphMap(MGraph* G);
void DFS(MGraph* G, int i, bool (&rvisited)[MAXVEX]);