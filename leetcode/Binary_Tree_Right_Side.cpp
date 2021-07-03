#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>
// 題目:
//注意是最右邊不是只有右邊
// Input: [1,2,3,null,5,null,4,null,6]
// Output: [1, 3, 4, 6]
// Explanation:
                // The level of resursion
//    1            <--- level 1
//  /   \
// 2     3         <--- level 2
//  \     \
//   5     4       <--- level 3
//    \
//     6           <--- level 4
using namespace std;
 //* Definition for a binary tree node.
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
    void t(TreeNode *root,vector<int> &temp,int level)
    {
        if(root==NULL)
            return ;
        if(temp.size()<level)//只放每個節點的最右邊因為當放完時size++且層數一樣的level一樣
            temp.push_back(root->val);
        cout<<level<<endl;
        t(root->right,temp,level+1);//注意level是當前遞迴的level(也就是每個結點的level為定值)去加1並非一直壘加
        t(root->left,temp,level+1);//每個結點的level剛好等於層數
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> temp;
        t(root,temp,1);
        return temp;
    }
};
//non recursion
class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int N = bfs.size(); //該層的結點數
            while (N--) {
                auto* curr = bfs.front(); //用queue的頭當結點
                bfs.pop();//下一個結點
                if (N == 0) result.push_back(curr->val);//代表指向最右邊 故放進vector
                if (curr->left) bfs.push(curr->left);//將下一層的所有結點放入
                if (curr->right) bfs.push(curr->right);
            }
        }
        return result;
    }
};