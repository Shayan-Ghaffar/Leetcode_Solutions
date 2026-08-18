class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == k)
            return *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int i : nums)
            freq[i]++;
        if (1 == k) {
            int maxi = -1;
            for (auto i : freq) {
                if (i.second == 1) {
                    maxi = max(maxi, i.first);
                }
            }
            return maxi;
        }
        int maxi = -1;
        if(freq[nums[0]] == 1)
            maxi = max(maxi, nums[0]);
        if(freq[nums[N-1]] == 1)
            maxi = max(maxi, nums[N-1]);
        return maxi;
    }
};