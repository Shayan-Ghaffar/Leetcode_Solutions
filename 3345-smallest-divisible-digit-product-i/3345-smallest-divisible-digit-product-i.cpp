class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i < 101; i++)
        {
            int num = i;
            int pro = 1;
            while(num)
            {
                pro = pro * (num % 10);
                num /= 10;
            }
            if(pro % t == 0)
                return i;
        }
        return 0;
    }
};