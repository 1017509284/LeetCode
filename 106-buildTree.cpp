/*
 * 根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos=postorder.size()-1;
        return buildTree(inorder,pos,postorder,0,postorder.size()-1);
    }
    TreeNode *buildTree(vector<int> &inorder,int &pos,vector<int> &postorder,
                        int left,int right)
    {
        if(pos<0)  return nullptr;
        int i=left;
        for(;i<right;i++)
        {
            if(inorder[i] == postorder[pos])
                break;
        }
        TreeNode *node=new TreeNode(postorder[pos]);
        //先要构造右子树，因为是后序遍历，--pos的值属于右子树
        if(i+1 <= right)
            node->right=buildTree(inorder,--pos,postorder,i+1,right);
        if(left<=i-1)
            node->left=buildTree(inorder,--pos,postorder,left,i-1);
        return node;



    }
};
