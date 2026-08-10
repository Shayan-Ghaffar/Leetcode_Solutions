class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mapo;
        vector<string> patterns;
        for(auto i: strs)
        {
            string s = i;
            sort(s.begin(), s.end());
            patterns.push_back(s);
        }
        for (int i = 0; i < strs.size(); i++) 
            mapo[patterns[i]].push_back(strs[i]);
        for(auto i: mapo)
            res.push_back(i.second);
        return res;
    }
};