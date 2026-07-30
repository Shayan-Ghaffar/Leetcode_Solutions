class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int> i : flights) {
            graph[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n, 1e9);
        q.push({0, {src, 0}});
        dis[src] = 0;
        while (!q.empty()) {
            int N = q.size();
            for (int i = 0; i < N; i++) {
                int stops = q.front().first;
                int node = q.front().second.first;
                int cost = q.front().second.second;
                q.pop();
                if (stops > k)
                    continue;
                for (int n = 0; n < graph[node].size(); n++) {
                    int adjNode = graph[node][n].first;
                    int adjCost = graph[node][n].second;
                    if (adjCost + cost < dis[adjNode]) {
                        dis[adjNode] = adjCost + cost;
                        q.push({stops + 1, {adjNode, adjCost + cost}});
                    }
                }
            }
        }
        if (dis[dst] == 1e9)
            return -1;
        return dis[dst];
    }
};