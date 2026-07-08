class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i: nums)
        {
           sum = max(i, sum + i);
           maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};