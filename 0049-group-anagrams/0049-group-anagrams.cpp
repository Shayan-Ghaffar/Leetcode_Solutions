class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mapo;
        for (int i = 0; i < strs.size(); i++) 
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mapo[s].push_back(strs[i]);
        }
        for(auto i: mapo)
        {
            res.push_back(i.second);
        }
        return res;
    }
};