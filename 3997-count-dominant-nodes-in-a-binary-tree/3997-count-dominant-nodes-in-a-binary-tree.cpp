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
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        LRV(root, count);
        return count;
    }
    int LRV(TreeNode* root, int& count)
    {
        if(!root)
            return 0;
        int left = -1;
        int right = -1;
        if(root->left)
            left = LRV(root->left, count);
        if(root->right)
            right = LRV(root->right, count);
        if(root->val >= left && root->val >= right)
        {
            count++;
        }
        return max(root->val, max(left, right));
    }
};