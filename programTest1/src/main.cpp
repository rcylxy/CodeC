#include <stdio.h>
#include "D:\homework\git\CodeC\programTest1\include\matrixGraph.h"
int main() {
  MGraph G;
  CreateMGraphMap(&G);
  bool visited[MAXVEX];
  bool(&rvisited)[MAXVEX] = visited;
  DFS(&G, 0, rvisited);
  return 0;
}

/*
gcc -c *.cpp
ar rcs lib*****.a *.o
gcc .\src\main.cpp -I include/ -L lib/ -l test -o main
*/