class Solution {
public:
    long long getDepth(int i, const vector<int>& parent,
                       vector<long long>& memo) {
        if (memo[i] != -1)
            return memo[i];
        return memo[i] = 1 + getDepth(parent[i], parent, memo);
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<long long> dept(parent.size(), -1);
        dept[0] = 1;
        for (int i = 0; i < parent.size(); i++) {
            getDepth(i, parent, dept);
        }
        long long height = *max_element(dept.begin(), dept.end());
        long long sum = 0;
        for (int i = 0; i < parent.size(); i++) {
            sum += ((long long)nums[i] * (height - dept[i] + 1));
        }
        return sum;
    }
};