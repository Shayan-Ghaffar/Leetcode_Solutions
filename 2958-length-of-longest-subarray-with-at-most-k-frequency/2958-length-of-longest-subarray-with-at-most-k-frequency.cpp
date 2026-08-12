class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int maxi = 0;
        int left = 0, right = 0;
        while(left <= right && right < nums.size())
        {
            m[nums[right]]++;
            while(m[nums[right]] > k)
            {
                m[nums[left]]--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};