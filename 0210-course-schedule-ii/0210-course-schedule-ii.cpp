class Solution {
public:
bool dfs(vector<vector<int>>& lis, vector<bool>& vis, vector<bool>& av, stack<int>& s, int i)
    {
        vis[i] = true;
        av[i] = true;
        bool possible = true;
        for(int j = 0; j < lis[i].size();j++)
        {
            if(!vis[lis[i][j]])
            {
                possible = dfs(lis, vis, av, s, lis[i][j]);
                if(!possible)
                    break;
            }
            else if(av[lis[i][j]])
            {
                possible = false;
                break;
            }
        }
        av[i] = false;
        s.push(i);
        return possible;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> lis(numCourses);
        for(vector<int> i: prerequisites)
        {
            lis[i[1]].push_back(i[0]);
        }
        vector<bool> vis(numCourses, false);
        stack<int> res;
        bool possible = true;
        for(int i = 0; i < numCourses; i++)
        {
            vector<bool> av(numCourses, false);
            if(!vis[i])
                possible = dfs(lis, vis, av, res, i);
            if(!possible)
                break;
        }
        vector<int> result;
        while(!res.empty())
        {
            result.push_back(res.top());
            res.pop();
        }
        if(!possible)
            return {};
        return result;
    }
};