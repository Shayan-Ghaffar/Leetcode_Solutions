class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.rbegin(), p.rend());
        sort(d.rbegin(), d.rend());
        double sum = 0;
        for(int i = 0; i < p.size();i++)
        {
            if(d.size() > i)
            {
                sum += (p[i] * (100.0 - d[i]) / 100.0);
            }
            else
                sum += p[i];
        }
        return sum;
    }
};