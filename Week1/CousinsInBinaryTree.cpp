/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int depth(TreeNode* root, int x,int d)
    {
        if(root == NULL)
            return -1;
        if(root->val == x)
            return d;

        int l = depth(root->left,x,d+1);
        if(l!=-1)
            return l;

        return depth(root->right,x,d+1);
    }

    bool isSibling(TreeNode* root, int x, int y)
    {
        if(root == NULL)
            return false;

        bool ans;
        if(root->left && root->right)
        {
            ans = ((root->left->val == x && root->right->val == y) ||
                  (root->left->val == y && root->right->val == x));
        }
        ans = ans || isSibling(root->left,x,y) || isSibling(root->right,x,y);
        return ans;
    }

public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        if(depth(root,x,0)!=depth(root,y,0))
            return false;
        if(isSibling(root,x,y))
            return false;

        return true;
    }
};