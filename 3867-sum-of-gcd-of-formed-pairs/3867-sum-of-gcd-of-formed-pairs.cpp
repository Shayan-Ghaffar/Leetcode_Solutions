class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> mxArray(nums.size(), -1);
        int maximum = nums[0];
        for(int i = 0; i < nums.size();i++)
        {
            maximum = max(nums[i], maximum);
            mxArray[i] = maximum;
        }
        vector<int> prefixGcd;
        for(int i = 0; i < nums.size();i++)
        {
            prefixGcd.push_back(gcd(nums[i], mxArray[i]));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long int sum = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++,j--)
        {
            sum += gcd(prefixGcd[i], prefixGcd[j]); 
        }
        return sum;
    }
};