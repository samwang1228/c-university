#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 題目:
// input為一個binary search tree
// 結果要為一個左子比右子大的樹
// 規律:
// 最右子不變，之後往上壘加
// ex:
// Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

// Input: root = [3,2,4,1]
// Output: [7,9,4,10]
//     3                              7  ->3+4
//   2   4   convert to   7+2    <- 9   4
// 1                      9+1  <- 10
 //Definition for a binary tree node.
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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        if(root->right)
            convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        if(root->left)
            convertBST(root->left);
        return root;
    }
private: int sum=0;
};