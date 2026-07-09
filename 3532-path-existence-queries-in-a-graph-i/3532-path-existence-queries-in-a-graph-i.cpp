class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        vector<int> check(n);
        int num = 0;
        check[0] = num;
        int k = 1;
        for(int i = 1; i < nums.size();i++)
        {
            if(abs(nums[i] - nums[i-1]) > maxDiff)
                num++;
            check[k] = num;
            k++;
        }
        int j = 0;
        for(vector<int> i: queries)
        {
            if(check[i[0]] == check[i[1]])
                res[j] = true;
            else
                res[j] = false;
            j++;
        }
        return res;
    }
};