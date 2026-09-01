class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        int ans = 0;
        int var = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0;i--)
        {
            ans = max(ans, var - prices[i]);
            if(var < prices[i])
                var = prices[i];
        }
        return ans;
    }
};