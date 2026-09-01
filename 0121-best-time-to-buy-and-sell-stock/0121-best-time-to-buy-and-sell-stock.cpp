class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        stack<int> mxs;
        int ans = 0;
        mxs.push(prices[prices.size() - 1]);
        for(int i = prices.size() - 2; i >= 0;i--)
        {
            ans = max(ans, mxs.top() - prices[i]);
            if(mxs.top() < prices[i])
                mxs.push(prices[i]);
        }
        return ans;
    }
};