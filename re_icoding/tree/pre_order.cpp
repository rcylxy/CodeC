#include "tree.h"
void pre_order(BiTree root);
int main()
{
  BiTree T;
  InitBiTree(&T);
  CreateBiTree(&T);
  TraverseTree(&T);
  printf("\n");
  pre_order(T);
}

/*
1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 -1 -1 11 -1 -1
*/