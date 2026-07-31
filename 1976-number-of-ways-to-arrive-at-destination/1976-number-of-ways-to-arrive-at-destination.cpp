class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> graph(n);
        for(auto i: roads)
        {
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> dis(n, 1e18);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        dis[0] = 0;
        int MOD = 1e9 + 7;
        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty())
        {
            long long cost = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto i: graph[node])
            {
                long long adjCost = i.second;
                long long adjNode = i.first;
                if(cost + adjCost < dis[adjNode])
                {
                    dis[adjNode] = cost + adjCost;
                    ways[adjNode] = ways[node];
                    pq.push({cost + adjCost, adjNode});
                }
                else if(cost + adjCost == dis[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};