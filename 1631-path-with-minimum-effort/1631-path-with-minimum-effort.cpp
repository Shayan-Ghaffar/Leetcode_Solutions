class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ef(n, vector<int>(m, 1e9));
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        ef[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int N = pq.size();
            for (int i = 0; i < N; i++) {
                int effort = pq.top().first;
                int X = pq.top().second.first;
                int Y = pq.top().second.second;
                if (X == n - 1 && Y == m - 1)
                    return effort;
                pq.pop();
                for (int d = 0; d < 4; d++) {
                    int newX = X + dx[d];
                    int newY = Y + dy[d];
                    if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                        int diff = abs(heights[newX][newY] - heights[X][Y]);
                        int maxi = max(effort, diff);
                        if (maxi < ef[newX][newY]) {
                            ef[newX][newY] = maxi;
                            pq.push({maxi, {newX, newY}});
                        }
                    }
                }
            }
        }
        return ef[n - 1][m - 1];
    }
};