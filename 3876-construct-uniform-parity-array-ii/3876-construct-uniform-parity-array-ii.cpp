class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e = INT_MAX;
        for(int i: nums1)
        {
            if(i % 2)
                e = min(e, i);
        }
        if(e == INT_MAX)
            return true;
        bool flag = true;
        for(int i: nums1)
            if(i % 2 == 0 && i < e)
            {
                flag = false;
                break;
            }
        return flag;
    }
};