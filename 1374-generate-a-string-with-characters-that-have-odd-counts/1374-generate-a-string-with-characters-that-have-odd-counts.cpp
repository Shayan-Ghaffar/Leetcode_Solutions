class Solution {
public:
    string generateTheString(int n) {
        string s;
        if(n % 2 == 0)
        {
            for(int i = 0; i < n - 1;i++)
                s += "a";
            s += 'b';
        }
        else if(n == 1)
            s += 'a';
        else if(n % 2 == 1)
        {
            for(int i = 0; i < n-2;i++)
                s += "a";
            s += "cb";
        }
        return s;
    }
};