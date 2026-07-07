class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff = 0;
        int N = s.length();
        int * arr = new int[26]{0};
        for(int i = 0; i < N; i++)
        {
            arr[s[i] - 'a'] += i;
            arr[t[i] - 'a'] -= i;
        }
        for(int i = 0; i < 26;i++)
        {
            if(arr[i] < 0)
                diff -= arr[i];
            else 
                diff += arr[i];
        }
        return diff;
    }
};