class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int total = n * 2;
        for(int i = 0; i < reservedSeats.size();i++)
        {
            int current = reservedSeats[i][0];
            bool first = true;
            bool second = true;
            bool third = true;
            while(i < reservedSeats.size() && reservedSeats[i][0] == current)
            {
                int check = reservedSeats[i][1];
                if(check == 2 || check == 3 || check == 4 || check == 5)
                    first = false;
                if(check == 4 || check == 5 || check == 6 || check == 7)
                    second = false;
                if(check == 6 || check == 7 || check == 8 || check == 9)
                    third = false;
                i++;
            }
            if(!first && !second && !third)
                total -= 2;
            else if(!first || !second || !third)
                total -= 1;
            i--;
        }
        return total;
    }
};