class Solution {
public:
    void dfs(int u, int& colorToDo, vector<int>& color,
             vector<vector<int>>& graph) {
        color[u] = colorToDo;
        for (int i = 0; i < graph[u].size(); i++) {
            if (colorToDo == 2 && color[graph[u][i]] == 1) {
                dfs(graph[u][i], colorToDo, color, graph);
            } else if (color[graph[u][i]] == 0) {
                dfs(graph[u][i], colorToDo, color, graph);
            }
        }
    }
    bool foundATwo(int u, int& colorToDo,
                   vector<int>& color, vector<vector<int>>& graph) {
        color[u] = 0;
        for (int i = 0; i < graph[u].size(); i++) {
            if (color[graph[u][i]] == 2)
                return true;
            if (color[graph[u][i]] == 1) {
                bool ans =
                    foundATwo(graph[u][i], colorToDo,color, graph);
                if (ans)
                    return true;
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> color(n, 0);
        vector<vector<int>> graph(n);
        for (auto i : invocations) {
            graph[i[0]].push_back(i[1]);
        }
        int col = 1;
        dfs(k, col, color, graph);
        col = 2;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                dfs(i, col, color, graph);
            }
        }
        col = 1;
        vector<int> mark = color;
        bool ans = foundATwo(k, col, mark, graph);
        vector<int> res;
        if (ans) {
            for (int i = 0; i < n; i++)
                res.push_back(i);
            return res;
        }
        for (int i = 0; i < n; i++) {
            if (color[i] == 1)
                continue;
            res.push_back(i);
        }
        return res;
    }
};