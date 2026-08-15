class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool zeroes = true;
        for(int i: nums)
        {
            if(i != 0)
                zeroes = false;
            x ^= i;
        }
        return zeroes? 0: (x == 0? nums.size() - 1: nums.size());
    }
};