class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] == b[0] ? a[1] > b[1]: a[0] < b[0];
        });
        int count = 0;
        int maxEnd = 0;
        for(int i = 0; i < intervals.size();i++)
        {
            if(intervals[i][1] > maxEnd)
            {
                maxEnd = intervals[i][1];
                count++;
            }
        }
        return count;
    }
};