class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> res(26, 0);
        for (char i : s)
            res[i - 97] += 1;
        int n = 0;
        int j = s.length() - 1;
        if ((j + 1) % 2) {
            for (char i = 'a'; i <= 'z'; i++) {
                if (res[i - 97] % 2) {
                    res[i - 97]--;
                    s[j + 2 / 2] = i;
                }
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            while (res[i - 97] > 0) {
                if (res[i - 97] > 0) {
                    s[n] = i;
                    res[i - 97]--;
                    n++;
                }
                if (res[i - 97] > 0) {
                    res[i - 97]--;
                    s[j] = i;
                    j--;
                }
            }
        }
        return s;
    }
};