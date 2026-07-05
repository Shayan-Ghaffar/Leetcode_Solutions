class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> heap;
        int j = 0;
        for(auto i: points)
        {
            double distance = pow((i[0] - 0), 2) + pow((i[1] - 0), 2);
            pair<double, int> res;
            res.first = distance;
            res.second = j;
            heap.push(res);
            j++;
        }
        vector<vector<int>> res;
        while(k--)
        {
            res.push_back(points[heap.top().second]);
            heap.pop();
        }
        return res;
    }
};