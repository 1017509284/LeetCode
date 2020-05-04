/*给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)   return res;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            TreeNode *node=q.front().first;
            int level=q.front().second;
            q.pop();

            if(level == res.size())
                res.push_back(vector<int>());
            
            res[level].push_back(node->val);

            // if(level%2!=0)
            // {
            //     if(node->left)
            //         q.push(make_pair(node->left,level+1));
            //     if(node->right)
            //         q.push(make_pair(node->right,level+1));
            // }
            // else
            // {
            //     if(node->right)
            //         q.push(make_pair(node->right,level+1));
            //     if(node->left)
            //         q.push(make_pair(node->left,level+1));
            // }
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                 q.push(make_pair(node->right,level+1));
        }
        for(int i=0;i<res.size();i++)
            {
                if(i%2!=0)
                {
                    int j=0;
                    int k=res[i].size()-1;
                    while(j<k)
                    {
                        swap(res[i][j],res[i][k]);
                        j++;
                        k--;
                    }
                }
            }
        return res;
    }
};
