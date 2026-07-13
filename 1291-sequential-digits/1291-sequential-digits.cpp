class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int q[45];
        int n = 0;
        for (int i = 1; i < 10; i++)
            q[n++] = i;
        for (int i = 0; i < n; i++) 
        {
            int d = q[i] % 10;
            if (d < 9) 
                q[n++] = q[i] * 10 + d + 1;
        }
        vector<int> res;
        for(int i = 0; i < n;i++)
        {
            if(q[i] >= low && q[i] <= high)
                res.push_back(q[i]);
        }
        return res;
    }
};