class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char i : s) {
            freq[i - 'a'] += 1;
        }
        vector<int> used(26, 0);
        int n = s.length();
        int i = 0;
        while (i < n) {
            int curr = target[i] - 'a';
            if (used[curr] == freq[curr])
                break;
            used[curr]++;
            i++;
        }
        while (i >= 0) {
            if (i < n) {
                int next = target[i] - 'a';
                for (int curr = next + 1; curr < 26; curr++) {
                    if (used[curr] == freq[curr])
                        continue;
                    string ans = target.substr(0, i);
                    ans += char(curr + 'a');
                    for (int i = 0; i < 26; i++) {
                        int rem = freq[i] - used[i];
                        if (curr == i)
                            rem--;
                        while (rem) {
                            ans += char(i + 'a');
                            rem--;
                        }
                    }
                    return ans;
                }
            }
            if (i > 0) {
                used[target[i - 1] - 'a']--;
            }
            i--;
        }
        return "";
    }
};