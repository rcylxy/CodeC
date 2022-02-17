#define MAX_TREE_SIZE 100
typedef int TElemType; //树中的数据的类型

//双亲表示法 parent_tree
typedef struct PTNode
{
  TElemType data; //结点的数据值
  int parent;     //该节点的双亲的存储位置
} PTNode;
typedef struct
{
  PTNode nodes[MAX_TREE_SIZE]; //存放树的数组
  int r, n;                    // r是根结点的位置，n是节点数
} PTree;                       //这就是P树的结构

//孩子表示法 child_tree
typedef struct CTNode //孩子结点
{
  int child;
  struct CTNode *next;
} * ChildPtr;  // CTNodePtr是一个指向孩子的pointer
typedef struct //表头结点
{
  TElemType data;
  ChildPtr firstchild;
} CTBox;
typedef struct
{
  CTBox nodes[MAX_TREE_SIZE]; //所有的结点数组
  int r, n;                   // r是根结点的位置，n是节点数
} CTree;                      //这就是C树的结构

//孩子兄弟表示法 child_sibling_tree
//这是将普通的树转化变成二叉树的最简单的方法
typedef struct CSNode
{
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} * CSTree, CSNode;