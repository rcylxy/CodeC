#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100       /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */
typedef enum
{
  OK,
  ERROR
} Status;
typedef int TElemType;
