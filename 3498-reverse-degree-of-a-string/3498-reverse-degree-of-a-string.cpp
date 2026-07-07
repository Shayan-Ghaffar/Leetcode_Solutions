class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int N = s.length();
        for(int i = 1; i <= N;i++)
        {
            sum += (int)(26 - (s[i - 1] - 'a')) * i;
        }
        return sum;
    }
};