class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        for(int i = 0; i < graph.size();i++)
        {
            if(graph[i].size() == 0)
                q.push(i);
        }
        vector<vector<int>> reversedGraph(graph.size());
        for(int i = 0; i < graph.size();i++)
        {
            for(int j = 0;j < graph[i].size();j++)
            {
                reversedGraph[graph[i][j]].push_back(i);
            }
        }
        vector<int> inDegree(graph.size(), 0);
        for(int i = 0; i < reversedGraph.size();i++)
        {
            for(int j = 0; j < reversedGraph[i].size();j++)
            {
                inDegree[reversedGraph[i][j]]++;
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            result.push_back(n);
            for(int i = 0; i < reversedGraph[n].size();i++)
            {
                inDegree[reversedGraph[n][i]]--;
                if(inDegree[reversedGraph[n][i]] == 0)
                {
                    q.push(reversedGraph[n][i]);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};