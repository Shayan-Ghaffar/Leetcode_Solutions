class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int i: nums)
            sum += i;
        int count = 0;
        int runningSum = 0;
        for(int i: nums)
        {
            runningSum += i;
            sum -= i;
            if(abs(runningSum - sum) % 2 == 0)
                count++;
        }
        if(count != 0)
            count--;
        return count;
    }
};