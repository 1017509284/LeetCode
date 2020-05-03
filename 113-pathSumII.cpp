/*
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode *root,int sum,vector<int> tmp)
    {
        tmp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val == sum)
            {
                res.push_back(tmp);
            }
        }
        if(root->left)  dfs(root->left,sum-root->val,tmp);
        if(root->right) dfs(root->right,sum-root->val,tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)  return res;
        dfs(root,sum,{});
        return res;
    }
};
