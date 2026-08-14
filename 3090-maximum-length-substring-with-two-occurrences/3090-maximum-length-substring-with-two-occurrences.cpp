class Solution {
public:
    int maximumLengthSubstring(string s) {
        int k = 2;
        unordered_map<int, int> mapo;
        int N = s.length();
        int right = 0, left = 0;
        int maxo = 0;
        while (left <= right && right < N) {
            mapo[s[right]]++;
            while (mapo[s[right]] > k) {
                mapo[s[left]]--;
                left++;
            }
            maxo = max(maxo, right - left + 1);
            right++;
        }
        return maxo;
    }
};