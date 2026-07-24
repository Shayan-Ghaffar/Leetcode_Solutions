class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXor;
        prefixXor.push_back(arr[0]);
        for(int i = 1; i < arr.size();i++)
        {
            prefixXor.push_back(prefixXor[i-1] ^ arr[i]);
        }
        vector<int> result;
        for(auto i: queries)
        {
            if(i[0] == 0)
            {
               result.push_back(prefixXor[i[1]]);
            }
            else
            {
                result.push_back(prefixXor[i[1]] ^ prefixXor[i[0] - 1]);
            }
        }
        return result;
    }
};