class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i: nums)
        {
            maxi = max(maxi, i);
            mini = min(mini, i);
            s.insert(i);
        }
        vector<int> res;
        for(int i = mini; i <= maxi; i++)
        {
            if(!s.count(i))
                res.push_back(i);
        }
        return res;
    }
};