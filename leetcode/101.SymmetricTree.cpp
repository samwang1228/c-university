// Link:https://leetcode.com/problems/binary-tree-level-order-traversal/
// 題目:Given the root of a binary tree, return the level order traversal of its nodes' 
// values. (i.e., from left to right, level by level).
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Input: root = [1]
// Output: [[1]]
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
    bool isMirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL&&t2==NULL)
            return true;
        else if(t1==NULL||t2==NULL)
            return false;
        return (t1->val==t2->val)&&(isMirror(t1->right,t2->left) && isMirror(t1->left,t2->right));
    }
};