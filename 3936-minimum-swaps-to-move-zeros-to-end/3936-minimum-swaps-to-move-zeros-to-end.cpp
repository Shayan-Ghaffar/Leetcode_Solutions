class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(right > 0 && nums[right] == 0)
            right--;
        int count = 0;
        while(left < right)
        {
            if(nums[left] == 0 && nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                count++;
                right--;
                left++;
            }
            else
                left++;
            while(nums[right] == 0)
                right--;
        }
        return count;
    }
};