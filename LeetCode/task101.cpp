#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
bool compare(struct TreeNode *left, struct TreeNode *right)
{
  if (left == NULL && right != NULL)
  {
    return false;
  }
  else if (left != NULL && right == NULL)
  {
    return false;
  }
  else if (left == NULL && right == NULL)
  {
    return true;
  }
  else if (left->val != right->val)
  {
    return false;
  }
  return compare(left->left, right->right) && compare(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
  if (!root)
    return true;
  return compare(root->left, root->right);
}
int main()
{
}