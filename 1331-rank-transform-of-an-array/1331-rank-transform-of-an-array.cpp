class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank = arr;
        sort(rank.begin(), rank.end());
        unordered_map<int, int> m;
        int r = 1;
        for (int i = 1; i <= rank.size(); i++) {
            if (!m.count(rank[i - 1])) {
                m[rank[i - 1]] = r;
                r++;
            }
        }
        rank.clear();
        for (int i : arr) {
            rank.push_back(m[i]);
        }
        return rank;
    }
};