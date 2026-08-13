class Solution {
    struct Node {
        char leftChar;
        char rightChar;
        int preLen;
        int sufLen;
        int maxLen;
    };
    vector<Node> tree;
    string str;
    void merge(int parent, int leftChild, int rightChild, int leftSize, int rightSize) {
        tree[parent].leftChar = tree[leftChild].leftChar;
        tree[parent].rightChar = tree[rightChild].rightChar;
        tree[parent].preLen = tree[leftChild].preLen;
        if (tree[leftChild].preLen == leftSize && tree[leftChild].rightChar == tree[rightChild].leftChar) {
            tree[parent].preLen += tree[rightChild].preLen; 
        }
        tree[parent].sufLen = tree[rightChild].sufLen;
        if (tree[rightChild].sufLen == rightSize && tree[leftChild].rightChar == tree[rightChild].leftChar) {
            tree[parent].sufLen += tree[leftChild].sufLen; 
        }
        tree[parent].maxLen = max(tree[leftChild].maxLen, tree[rightChild].maxLen);
        if (tree[leftChild].rightChar == tree[rightChild].leftChar) {
            int middleStreak = tree[leftChild].sufLen + tree[rightChild].preLen;
            tree[parent].maxLen = max(tree[parent].maxLen, middleStreak);
        }
    }
    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = {str[left], str[left], 1, 1, 1};
            return;
        }
        int mid = left + (right - left) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        build(leftChild, left, mid);
        build(rightChild, mid + 1, right);
        merge(node, leftChild, rightChild, mid - left + 1, right - mid);
    }
    void update(int node, int left, int right, int pos, char newChar) {
        if (left == right) {
            tree[node].leftChar = newChar;
            tree[node].rightChar = newChar;
            return;
        }
        int mid = left + (right - left) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        if (pos <= mid) {
            update(leftChild, left, mid, pos, newChar);
        } else {
            update(rightChild, mid + 1, right, pos, newChar);
        }
        merge(node, leftChild, rightChild, mid - left + 1, right - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        str = s;
        tree.resize(4 * n);
        build(1, 0, n - 1);
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].maxLen); 
        }
        return ans;
    }
};