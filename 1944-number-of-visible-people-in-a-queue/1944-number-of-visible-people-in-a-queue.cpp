class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        int n = heights.size() - 1;
        vector<int> res(heights.size());
        for(int i = heights.size() - 1; i >= 0; i--)
        {
            int count = 0;
            if(!s.empty())
            {
                while(!s.empty() && (heights[i] > s.top()))
                {
                    count++;
                    s.pop();
                }
            }
            if(!s.empty())
                res[n] = count + 1;
            else
                res[n] = count;
            n--;
            s.push(heights[i]);
        }
        return res;
    }
};