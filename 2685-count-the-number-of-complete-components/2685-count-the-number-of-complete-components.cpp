class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<bool> vis(n, false);
        for(vector<int> i: edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        int count = 0;
        int ed = 0, vertices = 0;
        for(int i = 0; i < n;i++)
        {
            if(!vis[i])
            {
                ed = 0, vertices = 0;
                dfs(adjList, i, vis, ed, vertices);
                ed /= 2;
                if(ed == (vertices*(vertices-1)/2))
                    count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& edges, int i, vector<bool>& vis, int& ed, int& vertices)
    {
        vis[i] = true;
        vertices++;
        for(int j = 0; j < edges[i].size();j++)
        {
            int check = edges[i][j];
            ed++;
            if(vis[check] == false)
            {
                dfs(edges, check, vis, ed, vertices);
            }
        }
    }
};