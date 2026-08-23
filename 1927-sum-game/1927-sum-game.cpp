class Solution {
public:
    bool sumGame(string num) {
        int mark1 = 0, mark2 = 0;
        int sum1 = 0, sum2 = 0;
        int N = num.size();
        for(int i = 0; i < N;i++)
        {
            if(num[i] == '?')
            {
                if(i < N / 2)
                    mark1++;
                else mark2++;
            }
            else
            {
                if(i < N / 2)
                    sum1 += num[i] - '0';
                else sum2 += num[i] - '0';
            }
        }
        return 2 * (sum1 - sum2) != 9 * (mark2 - mark1);
    }
};