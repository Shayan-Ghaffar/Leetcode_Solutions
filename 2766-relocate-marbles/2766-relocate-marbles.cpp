class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int N = moveFrom.size();
        unordered_set<int> s;
        for(int i: nums)
        {
            if(!s.count(i))
            {
                s.insert(i);
            }
        }
        for(int i = 0; i < N;i++)
        {
            if(s.count(moveFrom[i]))
            {
                s.erase(moveFrom[i]);
                s.insert(moveTo[i]);
            }
        }
        vector<int> res;
        for(int i: s)
        {
            res.push_back(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};