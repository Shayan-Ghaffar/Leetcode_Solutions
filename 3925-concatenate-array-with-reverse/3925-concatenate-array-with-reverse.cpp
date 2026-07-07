class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int N = nums.size();
        for(int i = N - 1; i>= 0;i--)
            nums.push_back(nums[i]);
        return nums;
    }
};