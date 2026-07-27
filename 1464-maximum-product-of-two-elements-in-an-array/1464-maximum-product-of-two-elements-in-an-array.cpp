class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int m = 0;
        for(int i = 0; i < nums.size();i++){
            for(int j = i + 1; j < nums.size();j++){
                long long product = (long long)(nums[i] - 1) * (nums[j] - 1);
                m = max(product, m);
            }
        }
        return m;
    }
};