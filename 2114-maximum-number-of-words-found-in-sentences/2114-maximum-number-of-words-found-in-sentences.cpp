class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = INT_MIN;
        for(string i: sentences)
        {
            int count = 0;
            for(char c: i)
            {
                if(c == ' ')
                    count++;
            }
            maxi = max(maxi, count);
        }
        return maxi + 1;
    }
};