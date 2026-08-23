class Solution {
public:
    vector<int> fact(vector<int>& spf, int n) {
        vector<int> ans;
        while (n > 1) {
            int p = spf[n];
            ans.push_back(p);
            while (n % p == 0)
                n /= p;
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        vector<int> spf(1e5 + 1);
        for (int i = 0; i <= 1e5; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= 1e5; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= 1e5; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
        int end = 0;
        int start = 0;
        unordered_map<int, int> mp;
        int len = INT_MIN;
        while (end < nums.size()) {
            vector<int> arr = fact(spf, nums[end]);
            for (auto i : arr)
                mp[i]++;
            while (start <= end && mp.size() > k) {
                vector<int> arr = fact(spf, nums[start]);
                for (auto i : arr) {
                    mp[i]--;
                    if (mp[i] == 0)
                        mp.erase(i);
                }
                start++;
            }
            len = max(len, end - start + 1);
            end++;
        }
        return len;
    }
};