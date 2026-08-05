class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        map<pair<int, int>, int> s;
        int count = 0;
        return sumPath(grid, 0, 0, s);
    }
    int sumPath(vector<vector<int>>& grid, int row, int col,
                map<pair<int, int>, int>& m) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return 1;
        if (row + 1 < grid.size()) {
            if (!m.count({row + 1, col}))
                m[{row + 1, col}] = sumPath(grid, row + 1, col, m);
        } 
        if (col + 1 < grid[0].size()) {
            if (!m.count({row, col + 1}))
                m[{row, col + 1}] = sumPath(grid, row, col + 1, m);
        } 
        return m[{row + 1, col}] + m[{row, col + 1}];
    }
};