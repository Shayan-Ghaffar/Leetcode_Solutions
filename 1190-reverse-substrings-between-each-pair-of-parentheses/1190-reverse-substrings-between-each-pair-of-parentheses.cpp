class Solution {
public:
    string reverseParentheses(string s) {
        stack<long long> rev;
        int N = s.length();
        for(int i = 0; i < N;i++)
        {
            if(s[i] == '(')
            {
                rev.push(i + 1);
            }
            else if(s[i] == ')')
            {
                reverse(s.begin() + rev.top(), s.begin() + i);
                rev.pop();
            }
        }
        string ans;
        for(char i: s)
        {
            if(i == '(' || i == ')')
                continue;
            ans += i;
        }
        return ans;
    }
};