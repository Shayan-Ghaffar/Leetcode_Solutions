class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(), -1);
        int n = graph.size();
        for(int i = 0; i < n; i++)
        {
            if(colored[i] == -1)
            {
                queue<int> q;
                q.push(i);
                colored[i] = 0;
                while (!q.empty())
                {
                    int val = q.front();
                    q.pop();
                    for (int neighbor : graph[val]) 
                    {
                        if (colored[neighbor] == -1) 
                        {
                            colored[neighbor] = 1 - colored[val];
                            q.push(neighbor);
                        } 
                        else if (colored[neighbor] == colored[val]) 
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};