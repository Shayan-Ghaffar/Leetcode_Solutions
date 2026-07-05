class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int equal = 0;
        for(int i: nums)
        {
            if(i == pivot)
                equal++;
            else if(i < pivot)
                less.push_back(i);
            else 
                greater.push_back(i);
        }
        vector<int> result;
        for(int i: less)
            result.push_back(i);
        for(int i = 0; i < equal;i++)
            result.push_back(pivot);
        for(int i: greater)
            result.push_back(i);
        return result;
    }
};