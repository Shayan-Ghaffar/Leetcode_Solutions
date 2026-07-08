class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxSum = INT_MIN;
        int sum = 0;
        while(right < nums.size())
        {
            sum += nums[right];
            maxSum =  max(sum, maxSum);
            while(sum < 0)
            {
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxSum;
    }
};