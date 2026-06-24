class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int N = moveFrom.size();
        unordered_set<int> s;
        vector<int> all;
        for(int i: nums)
        {
            if(!s.count(i))
            {
                all.push_back(i);
                s.insert(i);
            }
        }
        for(int i = 0; i < N;i++)
        {
            if(s.count(moveFrom[i]))
            {
                all.push_back(moveTo[i]);
                s.erase(moveFrom[i]);
                s.insert(moveTo[i]);
            }
        }
        vector<int> res;
        unordered_set<int> resultCheck;
        for(int i: all)
        {
            if(s.count(i) && !resultCheck.count(i))
            {
                res.push_back(i);
                resultCheck.insert(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};