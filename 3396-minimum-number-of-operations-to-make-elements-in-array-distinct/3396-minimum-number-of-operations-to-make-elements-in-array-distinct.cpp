class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool distinct = false;
        int count = 0;
        int i = 0;
        unordered_set<int> s;
        while(i < nums.size() && !nums.empty()){
            if(s.count(nums[i]))
            {
                if(nums.size() < 3)
                    nums.clear();
                else
                {
                    vector<int> copy;
                    for(int i = 3; i < nums.size();i++)
                    {
                        copy.push_back(nums[i]);
                    }
                    nums = copy;
                }
                i = -1;
                count++;
                s.clear();
            }
            else
                s.insert(nums[i]);
            i++;
        }
        return count;
    }
};