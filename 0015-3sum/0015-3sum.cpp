class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            m.clear();
            for(int j = i + 1; j < nums.size();j++)
            {
                if(m.count(target - nums[j]))
                {
                    vector<int> r(3, 0);
                    r[0] = nums[i];
                    r[1] = nums[j];
                    r[2] = target - nums[j];
                    res.push_back(r);
                    while (j + 1 < nums.size() && nums[j] == nums[j+1]) {
                        j++;
                    }
                    m[nums[j]] = 1;

                }
                else
                    m[nums[j]] = 1;
            }
        }
        return res;
    }
};