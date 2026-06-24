class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int step = k;
        while(true)
        {
            if(find(nums.begin(), nums.end(), k) == nums.end())
                return k;
            k += step;
        }
        return 0;
    }
};