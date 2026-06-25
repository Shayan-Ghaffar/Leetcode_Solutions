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
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        string s;
        return traverse(root, s);
    }
    int traverse(TreeNode*root, string s)
    {
        if(!root)
            return 0;
        s += (root->val + '0');
        if(!(root->left) && !root->right)
            return convertToBinary(s);
        int total = 0;
        cout << s << endl;
        if(root->left)
            total = traverse(root->left, s);
        if(root->right)
            total += traverse(root->right, s);
        return total;
    }
    int convertToBinary(string s)
    {
        int result = 0;
        int m = 0;
        int N = s.length();
        for(int i = N - 1; i >= 0; i--)
        {
            result = result + (s[i] - '0')*pow(2,m);
            m++;
        }
        return result;
    }
};