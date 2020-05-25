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
    int findIndex(vector<int>& preorder)
    {
        int n = preorder[0];

        for(int i = 1;i<preorder.size();i++)
        {
            if(preorder[i] > n)
                return i;
        }
        return preorder.size();
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        if(preorder.size() == 0)
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> left,right;
        int index = findIndex(preorder);

        for(int i=1;i<preorder.size();i++)
        {
            if(i<index)
                left.push_back(preorder[i]);
            else
                right.push_back(preorder[i]);
        }

        root->left = solve(left);
        root->right = solve(right);

        return root;
    }
};