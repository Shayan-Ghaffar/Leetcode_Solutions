class Solution {
public:
    string longestPalindrome(string s) {
        int size = INT_MIN;
        string longest;
        int N = s.length();
        for(int i = 0; i < N;i++)
        {
            for(int j = i; j < N;j++)
            {
                if(isPalindrome(s, i, j))
                {
                    if(j - i + 1 > size)
                    {
                        size = j - i + 1;
                        longest.resize(j-i+1);
                        int m = i;
                        for(int k = 0; k < j - i + 1;k++,m++)
                            longest[k] = s[m];
                    }
                }
            }
        }
        return longest;
    }
    bool isPalindrome(string& s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};