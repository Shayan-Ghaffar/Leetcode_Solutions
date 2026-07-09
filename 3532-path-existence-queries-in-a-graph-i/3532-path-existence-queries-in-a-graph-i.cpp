class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        vector<int> check(n-1);
        int j = 1;
        for(int i = 0; i < n - 1;i++)
        {
            check[i] = abs(nums[j] - nums[j-1]);
            j++;
            cout << check[i];
        }
        int k = 0;
        for(vector<int> i: queries)
        {
            bool pos = true;
            int x = max(i[0], i[1]);
            int y = min(i[0], i[1]);
            for(int j = y; j < x;j++)
            {
                if(check[j] > maxDiff)
                {
                    pos = false;
                    break;
                }
            }
            if(pos) res[k] = true;
            else res[k] = false;
            k++;
        }
        return res;
    }
};