class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> arr = nums;
        int maxi = INT_MAX;
        for(int i = nums.size() - 1; i >= 0;i--)
        {
            maxi = min(maxi, nums[i]);
            arr[i] = maxi;
        }
        int mini = INT_MIN;
        for(int i = 0; i < nums.size();i++)
        {
            mini = max(mini, nums[i]);
            if(abs(mini - arr[i]) <= k)
                return i;
        }
        return -1;
    }
};