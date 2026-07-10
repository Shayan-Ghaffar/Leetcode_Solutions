class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        board[i][j] = '.';
        if(i + 1 < board.size() && board[i+1][j] == 'X')
            dfs(i + 1, j, board);
        if(j + 1 < board[0].size() && board[i][j+1] == 'X')
            dfs(i, j+1, board);
        if(i - 1 >= 0 && board[i-1][j] == 'X')
            dfs(i - 1, j, board);
        if(j - 1 >= 0 && board[i][j-1] == 'X')
            dfs(i, j-1, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < board.size();i++)
        {
            for(int j = 0; j < board[0].size();j++)
            {
                if(board[i][j] == 'X')
                {
                    count++;
                    dfs(i, j, board);
                }
            }
        }
        return count;
    }
};