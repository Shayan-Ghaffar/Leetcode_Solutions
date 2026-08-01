class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dis(n, vector<long long>(n, 1e18));
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for(int i = 0; i < n;i++)
            dis[i][i] = 0;
        for(int via = 0; via < n;via++)
        {
            for(int i = 0; i < n;i++)
            {
                for(int j = 0;j < n;j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }
        int count = 0;
        int answer = -1;
        int min = INT_MAX;
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(dis[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if(count <= min)
            {
                min = count;
                answer = i;
            }
            count = 0;
        }
        return answer;
    }
};