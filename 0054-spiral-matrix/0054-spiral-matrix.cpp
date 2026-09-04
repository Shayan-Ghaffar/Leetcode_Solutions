class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int N = matrix.size();
        int M = matrix[0].size();
        int elements = matrix.size() * matrix[0].size();
        int t = 0;
        vector<int> cor = {0, M - 1, N - 1, 0};
        while (elements) {
            if (elements > 0)
                for (int i = 0 + t; i < M - t; i++) {
                    elements--;
                    cout << matrix[cor[0]][i] << " : ";
                    ans.push_back(matrix[cor[0]][i]);
                }
            if (elements > 0)
                for (int i = 1 + t; i < N - t; i++) {
                    elements--;
                    cout << matrix[i][cor[1]] << " : ";
                    ans.push_back(matrix[i][cor[1]]);
                }
            if (elements > 0)
                for (int i = M - 2 - t; i >= 0 + t; i--) {
                    elements--;
                    cout << matrix[cor[2]][i] << " : ";
                    ans.push_back(matrix[cor[2]][i]);
                }
            if (elements > 0)
                for (int i = N - 2 - t; i >= 1 + t; i--) {
                    elements--;
                    cout << matrix[i][cor[3]] << " : ";
                    ans.push_back(matrix[i][cor[3]]);
                }
            t++;
            cor[0]++;
            cor[1]--;
            cor[2]--;
            cor[3]++;
        }
        return ans;
    }
};