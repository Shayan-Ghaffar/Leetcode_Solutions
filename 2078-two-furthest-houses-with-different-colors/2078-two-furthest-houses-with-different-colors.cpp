class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left, right;
        int N = colors.size();
        for(int i = N - 1; i > 0; i--)
        {
            if(colors[0] != colors[i])
            {
                right = i;
                break;
            }
        }
        for(int i = 0; i < N - 1; i++)
        {
            if(colors[N - 1] != colors[i])
            {
                left = N - i - 1;
                break;
            }
        }
        return max(left, right);
    }
};