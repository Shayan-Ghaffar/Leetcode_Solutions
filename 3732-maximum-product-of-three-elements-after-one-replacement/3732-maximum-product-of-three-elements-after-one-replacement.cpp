class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int& i: nums)
            if(i < 0)
                i = -i;
        sort(nums.begin(), nums.end());
        return (long long)nums[nums.size()-1] * nums[nums.size() - 2] * 10e4;
    }
};