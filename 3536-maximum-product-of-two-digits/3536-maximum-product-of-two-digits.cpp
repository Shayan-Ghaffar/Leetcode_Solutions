class Solution {
public:
    int maxProduct(int n) {
        vector<int> res;
        while (n) {
            res.push_back(n % 10);
            n /= 10;
        }
        int max = -1;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res.size(); j++) {
                if (i != j && res[i] * res[j] > max) {
                    max = res[i] * res[j];
                }
            }
        }
        return max;
    }
};