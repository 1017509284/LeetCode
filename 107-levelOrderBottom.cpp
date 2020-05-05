/*给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)   return res;

        queue<pair<TreeNode *,int>> q;
        q.push(make_pair(root,0));

        while(!q.empty())
        {
            TreeNode *node=q.front().first;
            int level=q.front().second;
            q.pop();

            if(res.size() == level)
                res.push_back(vector<int>());

            res[level].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                q.push(make_pair(node->right,level+1));
        }

        int i=0;
        int j=res.size()-1;
        while(i<j)
        {
            swap(res[i++],res[j--]);
        }
        return res;
    }
};
