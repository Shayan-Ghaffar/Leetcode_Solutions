class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max = 10e-5;
        int secondMax = 10e-5;
        for(int i: nums)
        {
            if(i < 0)
                i = -i;
            if(max < i)
            {
                secondMax = max;
                max = i;
            }
            else if(secondMax < i)
                secondMax = i;
        }
        cout << max << " : " << secondMax << endl;
        return (long long)max * secondMax * 10e4;
    }
};