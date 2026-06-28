class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int total = INT_MIN;
        while (left <= right) 
        {
            total = max(total, min(height[left], height[right]) * (right - left));
            if(height[right] > height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return total;
    }
};