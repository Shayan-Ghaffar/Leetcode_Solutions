class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int mini = INT_MAX;
        vector<vector<pair<int, int>>> road(n + 1);
        for(auto i: roads)
        {
            road[i[0]].push_back({i[1], i[2]});
            road[i[1]].push_back({i[0], i[2]});
        }
        dfs(vis, road, q, mini);
        return mini;
    }
    void dfs(vector<bool>& vis, vector<vector<pair<int, int>>>& road, queue<int>& q,
             int& mini) {
        if (q.empty())
            return;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; i < road.size() && j < road[i].size();j++) {
                mini = min(mini, road[i][j].second);
                if(!vis[road[i][j].first])
                {
                    vis[road[i][j].first] = true;
                    q.push(road[i][j].first);
                }
            }
        }
    }
};