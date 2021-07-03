#include <iostream>
#include<stdio>
// 題目:
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
// Return true if and only if the nodes corresponding to the values x and y are cousins.
// Constraints:
// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.
// 意思x與y不能是同一個點分支出來且層數要一樣
//   4                 6
//  / \ false         / \ true
//  x y              5   7
//                  / \   \
//                  x  9   y  
 // Definition for a binary tree node.
 // using c
  struct TreeNode {
   struct TreeNode {
       int val;
       struct TreeNode *left;
       struct TreeNode *right;
  };
int getDepth(struct TreeNode*root,int target)
{
    if(root==NULL) return -1;
    if(root->val==target) return 0;
    int leftDepth=getDepth(root->left,target);
    int rightDepth=getDepth(root->right,target);
    if(leftDepth!=-1) return leftDepth+1;
    if(rightDepth!=-1) return rightDepth+1;
    return -1;
}
int getparent(struct TreeNode*root,int target)
{
    if(root==NULL) return -1;
    if(root->right==NULL&& root->left==NULL &&root->val!=target)
    {
        return -1;
    }
    if(root->left!=NULL&&root->left->val==target)
    {
        return root->val;
    }
    if(root->right!=NULL&&root->right->val==target)
    {
        return root->val;
    }
    int leftparent=getparent(root->left,target);
    int rightparent=getparent(root->right,target);
    if(leftparent!=-1)
    {
        return leftparent;
    }
    if(rightparent!=-1)
    {
        return rightparent;
    }
    return -1;
}

bool isCousins(struct TreeNode* root, int x, int y){
  int xDepth=getDepth(root, x);
       int yDerpth=getDepth(root,y);
       int xparent=getparent(root,x);
       int yparent=getparent(root,y);
       return xDepth==yDerpth&&xparent!=yparent;
}