class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        int left = 0, right = k - 1;
        unordered_map<int, int> mapo;
        while (right < nums.size()) {
            unordered_set<int> seto;
            for (int i = left; i <= right; i++) {
                if (!seto.count(nums[i]))
                    mapo[nums[i]]++;
                seto.insert(nums[i]);
            }
            left++;
            right++;
        }
        for (auto i : mapo) {
            if (i.second == 1) {
                ans = max(ans, i.first);
            }
        }
        return ans;
    }
};