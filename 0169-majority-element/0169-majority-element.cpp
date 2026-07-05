class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int majority = -1;
        int i = 0;
        for(; i < nums.size();i++)
        {
            if(counter == 0)
                majority = nums[i];
            if(nums[i] == majority)
                counter++;
            else
            {
                counter--;
            }
        }
        if(counter == 0)
            majority = nums[i];
        return majority;
    }
};