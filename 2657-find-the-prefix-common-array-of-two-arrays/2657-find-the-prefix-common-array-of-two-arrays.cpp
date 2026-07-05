class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < A.size();i++)
        {
            if(!m.count(A[i]))
                m[A[i]] = 1;
            else
                m[A[i]]++;
            if(!m.count(B[i]))
                m[B[i]] = 1;
            else
                m[B[i]]++;
            int count = 0;
            for(auto i: m)
                if(i.second == 2)
                    count++;
            res.push_back(count);
        }
        return res;
    }
};