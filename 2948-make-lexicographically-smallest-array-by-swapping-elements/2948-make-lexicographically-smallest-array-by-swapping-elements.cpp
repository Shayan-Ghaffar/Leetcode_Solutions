class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> index;
        for(int i = 0; i < nums.size();i++)
            index.push_back({nums[i], i});
        sort(index.begin(), index.end());
        vector<vector<int>> groups = {{index[0].second}};
        for(int i = 1; i < index.size();i++)
        {
            if(index[i].first - index[i-1].first <= limit)
                groups.back().push_back(index[i].second);
            else
                groups.push_back({index[i].second});
        }
        for(auto& group: groups)
        {
            vector<int> vals;
            for(int i = 0; i < group.size();i++)
            {
                vals.push_back(nums[group[i]]);
            }
            sort(group.begin(), group.end());
            for(int i = 0; i < group.size();i++)
                nums[group[i]] = vals[i];
        }
        return nums;
    }
};