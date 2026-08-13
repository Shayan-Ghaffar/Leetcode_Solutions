struct Node{
    int sum = 0;
};
class NumArray {
    void updateHelper(int node, int l, int r, int index, int val) {
        if (l == r) {
            tree[node].sum = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateHelper(2 * node, l, mid, index, val);
        } else {
            updateHelper(2 * node + 1, mid + 1, r, index, val);
        }
        merge(node);
    }
    
    int sumRangeHelper(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node].sum;
        }
        if (r < ql || l > qr) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int leftSum = sumRangeHelper(2 * node, l, mid, ql, qr);
        int rightSum = sumRangeHelper(2 * node + 1, mid + 1, r, ql, qr);
        return leftSum + rightSum;
    }
public:
    vector<Node> tree;
    int N;
    void merge(int node)
    {
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }
    void build(int node, int left, int right, vector<int>& nums)
    {
        if(left == right)
        {
            tree[node].sum = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(2 * node,left, mid, nums);
        build(2 * node + 1, mid + 1, right, nums);
        merge(node);
    }
    NumArray(vector<int>& nums) {
        tree.resize(nums.size() * 4);
        N = nums.size();
        build(1, 0, nums.size() - 1, nums);
    }
    
    void update(int index, int val) {
        updateHelper(1, 0, N-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(1, 0, N-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */