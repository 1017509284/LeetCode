/*给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)   return nullptr;
        vector<int> ans;
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            ans.push_back(cur->val);
            cur=cur->next;
        }
        return sortedArrayToBST(ans);
    }
    TreeNode *sortedArrayToBST(vector<int> &ans)
    {
        if(ans.size()==0)   return nullptr;
        int mid=ans.size()/2;
        TreeNode *root=new TreeNode(ans[mid]);
        vector<int> l;
        vector<int> r;
        for(int i=0;i<mid;i++)
            l.push_back(ans[i]);
        for(int i=mid+1;i<ans.size();i++)
            r.push_back(ans[i]);

        root->left=sortedArrayToBST(l);
        root->right=sortedArrayToBST(r);

        return root;
    }
};
