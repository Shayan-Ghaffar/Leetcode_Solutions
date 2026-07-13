class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int unRotten = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size();i++)
        {
            for(int j = 0; j < grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                    unRotten++;
                if(grid[i][j] == 2)
                {
                    pair<int, int> p = {i, j};
                    q.push(p);
                }
            }
        }
        if(unRotten == 0)
            return 0;
        int count = 0;
        int rotten = 0;
        while(!q.empty())
        {
            int N = q.size();
            for(int i = 0; i < N;i++)
            {
                pair<int, int> pa = q.front();
                q.pop();
                int x = pa.first;
                int y = pa.second;
                if(x - 1 >= 0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    rotten++;
                    pa.first = x - 1;
                    pa.second = y;
                    q.push(pa);
                }
                if(y - 1 >= 0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    rotten++;
                    pa.first = x;
                    pa.second = y-1;
                    q.push(pa);
                }
                if(y + 1 < grid[0].size() && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    rotten++;
                    pa.first = x;
                    pa.second = y+1;
                    q.push(pa);
                }
                if(x + 1 < grid.size() && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    rotten++;
                    pa.first = x + 1;
                    pa.second = y;
                    q.push(pa);
                }
            }
            count++;
        }
        return (rotten == unRotten? count - 1: -1);
    }
};