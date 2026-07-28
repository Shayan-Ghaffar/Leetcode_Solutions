class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i: nums)
        {
           sum = max(i, sum + i);
           maxSum = max(sum, maxSum);
        }
        for(int& i: nums)
        {
            i = -i;
        }
        int minSum = INT_MIN;
        sum = 0;
        for(int i: nums)
        {
           sum = max(i, sum + i);
           maxSum = max(sum, maxSum);
        }
        return max(minSum, maxSum);
    }
};