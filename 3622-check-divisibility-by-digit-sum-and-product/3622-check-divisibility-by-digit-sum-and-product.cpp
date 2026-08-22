class Solution {
public:
    bool checkDivisibility(int n) {
        unsigned long long sum = 0;
        unsigned long long product = 1;
        int val = n;
        while (val) {
            int rem = val % 10;
            sum += rem;
            product *= rem;
            val /= 10;
        }
        return (n % (sum + product)) == 0;
    }
};