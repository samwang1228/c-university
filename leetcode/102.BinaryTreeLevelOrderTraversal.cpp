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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            cout<<size<<endl;
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }
};