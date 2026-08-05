class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int, int>, int> m;
        return sumPath(grid, 0, 0, m);
    }
    int sumPath(vector<vector<int>>& grid, int row, int col,
                map<pair<int, int>, int>& m) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        if (m.count({row, col}))
            return m[{row, col}];
        int down = INT_MAX, right = INT_MAX;

        if (row + 1 < grid.size()) {
            if (m.count({row + 1, col}))
                down = m[{row + 1, col}];
            else {
                m[{row + 1, col}] = sumPath(grid, row + 1, col, m);
                down = m[{row + 1, col}];
            }
        }
        if (col + 1 < grid[0].size()) {
            if (m.count({row, col + 1}))
                right = m[{row, col + 1}];
            else {
                m[{row, col + 1}] = sumPath(grid, row, col + 1, m);
                right = m[{row, col + 1}];
            }
        }
        m[{row, col}] = grid[row][col] + min(down, right);
        return m[{row, col}];
    }
};