class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size();i++)
        {
            unordered_set<int> s;
            int even = 0;
            int odd = 0;
            for(int j = i; j < nums.size();j++)
            {
                if(!s.count(nums[j]))
                {
                    s.insert(nums[j]);
                    if(nums[j] % 2)
                        odd++;
                    else
                        even++;
                }
                if(odd == even)
                    count = max(count, j - i + 1);
            }
        }
        return count;
    }
};