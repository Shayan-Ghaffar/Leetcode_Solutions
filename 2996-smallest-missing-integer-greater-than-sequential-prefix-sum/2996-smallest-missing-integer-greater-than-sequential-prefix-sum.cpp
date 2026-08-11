class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i - 1] + 1 == nums[i])
                sum += nums[i];
            else
                break;
        }
        unordered_set<int> s;
        for(int i: nums)   
            s.insert(i);
        while(true)
        {
            if(s.count(sum))
                sum++;
            else
                return sum;
        }
        return 0;
    }
};