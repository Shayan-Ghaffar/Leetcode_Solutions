class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res = mat;
        queue<pair<int,int>> q;
        for(int i = 0; i < mat.size();i++)
        {
            for(int j = 0; j < mat[0].size();j++)
            {
                if(mat[i][j] == 0)
                {
                    pair<int, int> pa = {i , j};
                    q.push(pa);
                    res[i][j] = 0;
                }
            }
        }
        int count = 0;
        while(!q.empty())
        {
            count++;
            int N = q.size();
            for(int i = 0; i < N;i++)
            {
                pair<int, int> pa = q.front();
                q.pop();
                int x = pa.first;
                int y = pa.second;
                if(x - 1 >= 0 && mat[x-1][y] == 1)
                {
                    mat[x-1][y] = 0;
                    res[x-1][y] = count;
                    pa.first = x - 1;
                    pa.second = y;
                    q.push(pa);
                }
                if(y - 1 >= 0 && mat[x][y-1] == 1)
                {
                    mat[x][y-1] = 0;
                    res[x][y-1] = count;
                    pa.first = x;
                    pa.second = y-1;
                    q.push(pa);
                }
                if(y + 1 < mat[0].size() && mat[x][y+1] == 1)
                {
                    mat[x][y+1] = 0;
                    res[x][y+1] = count;
                    pa.first = x;
                    pa.second = y+1;
                    q.push(pa);
                }
                if(x + 1 < mat.size() && mat[x+1][y] == 1)
                {
                    mat[x+1][y] = 0;
                    res[x+1][y] = count;
                    pa.first = x + 1;
                    pa.second = y;
                    q.push(pa);
                }
            }
        }
        return res;
    }
};