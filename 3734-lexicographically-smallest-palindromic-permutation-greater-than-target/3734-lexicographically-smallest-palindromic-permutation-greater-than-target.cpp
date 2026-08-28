class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        if(s.length() == 1 && target.length() == 1 && s > target)
            return s;
        unordered_map<int, int> mp;
        for (char c : s)
            mp[c]++;
        bool twoOdd = false;
        int odd = 0;
        char oddChar;
        for (auto i : mp) {
            if (i.second % 2 == 1) {
                oddChar = i.first;
                odd++;
            }
        }
        if (odd > 1)
            return "";
        string sL;
        string targetL;
        for (auto i : mp) {
            int size = i.second;
            size /= 2;
            while (size--)
                sL.push_back(i.first);
        }
        int N = s.length();
        for (int i = 0; i < N / 2; i++)
            targetL.push_back(target[i]);
        string exactPal = targetL + (odd ? string(1, oddChar) : "") +
                           string(targetL.rbegin(), targetL.rend());
        string sortedSL = sL, sortedTargetL = targetL;
        sort(sortedSL.begin(), sortedSL.end());
        sort(sortedTargetL.begin(), sortedTargetL.end());
        string ans = (sortedSL == sortedTargetL && exactPal > target)
                         ? targetL
                         : getFirstHalf(sL, targetL);
        string rev = ans;
        if (odd && !ans.empty())
            ans.push_back(oddChar);
        reverse(rev.begin(), rev.end());
        ans += rev;
        if (ans > target)
            return ans;
        return "";
    }
    string getFirstHalf(string s, string target) {
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