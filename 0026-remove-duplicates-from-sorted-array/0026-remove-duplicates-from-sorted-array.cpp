class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> res;
        int cnt = 1;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (!(nums[i] == nums[i - 1])) {
                res.push_back(nums[i]);
                cnt++;
            }
        }
        nums = res;
        return cnt;
    }
};