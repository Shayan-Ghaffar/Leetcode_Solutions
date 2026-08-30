class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto mini = min_element(nums.begin(), nums.end());
        auto maxi = max_element(nums.begin(), nums.end());
        if(mini == maxi)
        {
            return min(mini - nums.begin() + 1, nums.end() - mini);
        }
        int diff = min(mini - nums.begin() + 1, nums.end() - mini);
        int diff2 = min(maxi - nums.begin() + 1, nums.end() - maxi);
        int diff3 = abs(mini - maxi);
        return min(min(diff + diff2, diff2 + diff3), diff + diff3);
    }
};