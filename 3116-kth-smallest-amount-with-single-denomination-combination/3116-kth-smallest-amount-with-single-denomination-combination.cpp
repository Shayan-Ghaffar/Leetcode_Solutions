#define ll long long
class Solution {
public:
    long long getCount(vector<int>& coins, ll x)
    {
        ll m = coins.size();
        ll allOnes = (1 << m) - 1;
        ll count = 0;
        for(ll mask = 1; mask <= allOnes;mask++)
        {
            ll setLcm = 1;
            for(int j = 0; j < m;j++)
            {
                if((mask) & (1 << j))
                    setLcm = lcm(setLcm, coins[j]);
            }
            if(__builtin_popcount(mask) & 1)
                count += x / setLcm;
            else
                count -= x / setLcm;
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l = 1, r = 25 * 2 * 1e9 + 25, ans = 0;
        while(l <= r)
        {
            ll mid = (l + r) / 2;
            ll count = getCount(coins, mid);
            if(count < k)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        } 
        return ans;
    }
};