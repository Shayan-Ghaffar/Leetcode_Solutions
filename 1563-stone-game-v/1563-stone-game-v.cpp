class Solution {
public:
    int solve(int start, int end, vector<int>& nums, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int l = 0, r = 0;
        for (int i = start; i <= end; i++) {
            r += nums[i];
        }
        int ans = 0;
        for (int i = start; i < end; i++) {
            l += nums[i];
            r -= nums[i];
            if (l < r)
                ans = max(ans, l + solve(start, i, nums, dp));
            else if (l == r)
                ans = max(ans, max(l + solve(start, i, nums, dp),
                                   r + solve(i + 1, end, nums, dp)));
            else
                ans = max(ans, r + solve(i + 1, end, nums, dp));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size(),
                               vector<int>(stoneValue.size(), -1));
        return solve(0, stoneValue.size() - 1, stoneValue, dp);
    }
};