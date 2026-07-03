class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1);
        res[0] = first;
        int k = 1;
        for(int i = 0; i < encoded.size();i++)
        {
            res[k] = res[k-1] ^ encoded[i];
            k++;
        }
        return res;
    }
};