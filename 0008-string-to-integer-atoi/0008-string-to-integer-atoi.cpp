class Solution {
public:
    int myAtoi(string s) {
       bool minus = false;
       bool plus = false;
       int N = s.length();
       int i = 0;
       while(i < N && s[i] == ' ')
            i++;
       if(s[i] == '-')
       {
            i++;
            minus = true;
       }
       else if(s[i] == '+')
       {
            i++;
            plus = true;
       }
       long long int check = (long long int)INT_MAX + 1;
       long long int ans = 0;
       while(i < N && s[i] >= '0' && s[i] <= '9')
       {
            ans = (ans * 10) + (s[i] - '0');
            if(minus && ans >= check)
                ans = check;
            else if(ans > INT_MAX)
                ans = INT_MAX;
            i++;
       }
       if(minus)
            ans = -ans;
        if(ans < INT_MIN)
            ans = INT_MIN;
        else if(ans > INT_MAX)
            ans = INT_MAX;
        return ans;
    }
};