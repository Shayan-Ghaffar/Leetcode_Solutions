class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0;
        int n = s.length();
        int r = 0;
        bool first = true;
        string ans;
        int nos = 0;
        while (r < n) {
            if (s[r] == '1') {
                nos++;
            }
            if (nos >= k)
            {
                while (l <= r && nos > k) {
                    if (s[l] == '1') {
                        nos--;
                    }
                    l++;
                }
                while(l <= r && s[l] == '0')
                    l++;
            }    
            if (nos == k) {
                string res(s.begin() + l, s.begin() + r + 1);
                if (first) {
                    first = false;
                    ans = res;
                } else {
                    if (ans.length() > res.length())
                        ans = res;
                    else if (ans > res && ans.length() == res.length())
                        ans = res;
                }
                cout << ans << endl;
            }
            r++;
        }
        while (l < n) {
            if (s[l] == '1')
                nos--;
            while(l <= r && s[l] == '0')
                l++;
            if (nos == k) {
                string res(s.begin() + l + 1, s.end());
                if (first) {
                    first = false;
                    ans = res;
                } else {
                    if (ans.length() > res.length())
                        ans = res;
                    else if (ans > res && ans.length() == res.length())
                        ans = res;
                }
            }
            l++;
        }
        return ans;
    }
};