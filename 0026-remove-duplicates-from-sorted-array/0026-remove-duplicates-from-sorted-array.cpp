class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int cnt = 0;
        int i = 0;
        for (;i < nums.size(); i++) {
             if(nums[cnt] != nums[i])
            {
                cnt++;
                nums[cnt] = nums[i];
            }
        }
        return cnt + 1;
    }
};