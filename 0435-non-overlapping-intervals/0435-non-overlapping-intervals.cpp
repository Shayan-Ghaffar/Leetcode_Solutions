class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        for(vector<int> i: intervals)
            cout << i[0] << " : " << i[1] << endl;
        int count = 0;
        int maxEnd = INT_MIN;
        for(int i = 0; i < intervals.size();i++)
        {
            if(intervals[i][0] >= maxEnd)
            {
                maxEnd = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};