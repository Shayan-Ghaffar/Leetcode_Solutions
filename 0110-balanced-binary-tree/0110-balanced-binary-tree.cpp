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
public:
    bool isBalanced(TreeNode* root) {
        return traverse(root) == -1? 0: 1;
    }
    int traverse(TreeNode* root)
    {
        if(!root)
            return -2;
        if(root && !(root->left) && !(root->right))
            return 1;
        int left = -2, right = -2;
        if(root->left)
            left = traverse(root->left);
        if(root->right)
            right = traverse(root->right);
        if(left == -1 || right == -1)
            return -1;
        if(right == -2 || left == -2)
            return max(left, right) > 1? -1: max(left, right) + 1;
        return abs(left - right) > 1? -1: max(left, right) + 1; 
    }
};