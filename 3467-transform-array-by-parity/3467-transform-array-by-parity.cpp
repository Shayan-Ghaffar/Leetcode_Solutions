class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(mid <= right)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                mid++;
                left++;
            }
            else if(nums[mid] == 1)
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
        return nums;
    }
};