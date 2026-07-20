class Solution {
public:
    vector<int> getSorted(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        return digits;
    }
    bool reorderedPowerOf2(int n) {
        map<vector<int>, bool> m;
        for (int i = 0; i < 30; i++) {
            m[getSorted(1 << i)] = true;
        }
        return m[getSorted(n)];
    }
};