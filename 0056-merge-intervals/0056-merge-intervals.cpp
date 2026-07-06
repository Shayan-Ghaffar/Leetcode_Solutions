class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        res.reserve(intervals.size());
        int k = 0;
        vector<int> j(2, -1);
        for(int i = 1; i < intervals.size();i++)
        {
            if(intervals[i][0] > end)
            {
                j[0] = start;
                j[1] = end;
                res.push_back(j);
                start = intervals[i][0];
                end =  intervals[i][1];
            }
            else 
            {
                end = max(intervals[i][1], end);
            }
        }
        j[0] = start;
        j[1] = end;
        res.push_back(j);
        return res;
    }
};