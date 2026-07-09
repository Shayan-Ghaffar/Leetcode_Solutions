class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int te = 0, a = 0, b = 0;
        int N = s.length();
        int M = t.length();
        while(te < M)
        {
            if(b < N)
            {
                if(s[b] == t[te])
                {
                    b++;
                }
            }
            if(a < N)
            {
                if(s[a] == t[te])
                {
                    a++;
                }
                else
                    b = max(b, a + 1);
            }
            te++;
        }
        return (a == N || b == N);
    }
};