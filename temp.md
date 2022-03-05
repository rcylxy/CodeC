```cpp
bool path(BiTNode *root, BiTNode *node, Stack *s)
{
  BiTNode *p, *q; // ElemType p;
  p = root;
  q = NULL;
  init_stack(s);

  if (p == NULL || node == NULL)
    return false;
  if (p == node)
  {
    push(s, p);
    return true;
  }

  while (p != NULL || !is_empty(s))
  { //访问左子树
    while (p)
    {
      push(s, p);    //非空就先压进去
      if (p == node) // node已经压进去了
        return true;
      p = p->left; //先根遍历
    }
    //访问右子树
    top(s, &p); //回到分支的根
    if (p->right == q || p->right == NULL)
    {
      q = p;      //第一个判断条件很关键, 判是否已经遍历过
      pop(s, &p); //左子树前面的while遍历了, 该结点的右子树遍历了或者为空就不要这个节点了
      p = NULL;   //置空就不会被再次压入 ,过前面的while循环,  等待下一次top赋值, 层次-1//这里指针断了
                  //需要注意的是p虽然指向该节点但是置空, 该结点任然存在, 并且q结点指向避免再次访问
    }
    else
    {
      p = p->right;
    }
  }

  return false;
}
```