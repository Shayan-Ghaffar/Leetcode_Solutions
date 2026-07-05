class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1, 0);
        vector<int> res;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (A[i] == B[i] && freq[A[i]] == 2)
                count++;
            else {
                if (freq[A[i]] == 2)
                    count++;
                if (freq[B[i]] == 2)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};