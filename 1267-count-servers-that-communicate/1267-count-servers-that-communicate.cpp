class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        long long count = 0;
        for (int i = 0; i < grid.size(); i++) {
            int co = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0)
                    co++;
            }
            if (co > 1) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] != 0)
                        grid[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            int co = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] != 0)
                    co++;
            }
            if (co > 1) {
                for (int j = 0; j < grid.size(); j++) {
                    if (grid[j][i] != 0)
                        grid[j][i] = 2;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    count++;
            }
        }
        return count;
    }
};