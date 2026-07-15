class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        pair<int, int> p = {i, j};
        q.push(p);
        int count = 0;
        while (!q.empty()) {
            int N = q.size();
            for (int i = 0; i < N; i++) {
                pair<int, int> pa = q.front();
                q.pop();
                count++;
                int x = pa.first;
                int y = pa.second;
                grid[x][y] = 0;
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 0;
                    pa.first = x - 1;
                    pa.second = y;
                    q.push(pa);
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 0;
                    pa.first = x;
                    pa.second = y - 1;
                    q.push(pa);
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 0;
                    pa.first = x;
                    pa.second = y + 1;
                    q.push(pa);
                }
                if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 0;
                    pa.first = x + 1;
                    pa.second = y;
                    q.push(pa);
                }
            }
        }
        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 1) {
                bfs(grid, i, 0);
            }
            if (grid[0].size() > 1)
                if (grid[i][grid[0].size() - 1] == 1) {
                    bfs(grid, i, grid[0].size() - 1);
                }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] == 1) {
                bfs(grid, 0, i);
            }
            if (grid.size() > 1)
                if (grid[grid.size() - 1][i] == 1) {
                    bfs(grid, grid.size() - 1, i);
                }
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count += bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};