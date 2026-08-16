class Solution {
public:
    int minOperations(string s) {
        int minCost = INT_MAX;
        int left = 0;
        int right = s.length() - 1;
        int size = right + 1;
        s += s;
        int st = 0;
        for(; right < size * 2 - 1;right++, left++)
        {
            int cost = st;
            int l = left, r = right;
            int diff = 0;
            while(l < r)
            {
                diff = abs(s[l] - s[r]);
                diff = min(diff, 26 - diff);
                cost += diff;
                l++;
                r--;
            }
            minCost = min(minCost, cost);
            st++;
        }
        return minCost;
    }
};