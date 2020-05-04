/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos=0;
        return buildTree(preorder,pos,inorder,0,inorder.size());
    }
    TreeNode *buildTree(vector<int> &preorder,int &pos,vector<int> &inorder,
                        int left,int right) {
        if(pos >= inorder.size())
            return nullptr;
        int i=left;
        for(;i<=right;i++)
        {
            if(preorder[pos] == inorder[i])
                break;
        }
        TreeNode *node=new TreeNode(preorder[pos]);
        if(left<=i-1)
            node->left=buildTree(preorder,++pos,inorder,left,i-1);
        if(i+1<=right)
            node->right=buildTree(preorder,++pos,inorder,i+1,right);
        return node;
    }
};
