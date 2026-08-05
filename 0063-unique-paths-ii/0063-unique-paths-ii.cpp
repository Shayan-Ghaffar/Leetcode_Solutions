class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        map<pair<int, int>, int> s;
        int count = 0;
        return sumPath(obstacleGrid, 0, 0, s);
    }
    int sumPath(vector<vector<int>>& grid, int row, int col,
                map<pair<int, int>, int>& m) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return 1;
        if (row + 1 < grid.size() && grid[row + 1][col] != 1) {
            if (!m.count({row + 1, col}))
                m[{row + 1, col}] = sumPath(grid, row + 1, col, m);
        }
        if (col + 1 < grid[0].size() && grid[row][col + 1] != 1) {
            if (!m.count({row, col + 1}))
                m[{row, col + 1}] = sumPath(grid, row, col + 1, m);
        }
        return m[{row + 1, col}] + m[{row, col + 1}];
    }
};