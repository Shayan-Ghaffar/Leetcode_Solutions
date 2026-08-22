class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int multiplier = 1;
        while(num)
        {
            int rem = num % 10;
            if(multiplier == 1)
            {
                if(rem == 4)
                {
                    ans.push_back('V');
                    ans.push_back('I');
                }
                else if(rem == 9)
                {
                    ans.push_back('X');
                    ans.push_back('I');
                }
                else if(rem < 4)
                {
                    while(rem--)
                    {
                        ans.push_back('I');
                    }
                }
                else if(rem >= 5)
                {
                    int toAdd = rem - 5;
                    while(toAdd)
                    {
                        ans.push_back('I');
                        toAdd--;
                    }
                    ans.push_back('V');
                }
            }
            else if(multiplier == 10)
            {
                if(rem == 4)
                {
                    ans.push_back('L');
                    ans.push_back('X');
                }
                else if(rem == 9)
                {
                    ans.push_back('C');
                    ans.push_back('X');
                } 
                else if(rem < 4)
                {
                    while(rem--)
                    {
                        ans.push_back('X');
                    }
                }
                else if(rem >= 5)
                {
                    int toAdd = rem - 5;
                    while(toAdd)
                    {
                        ans.push_back('X');
                        toAdd--;
                    }
                    ans.push_back('L');
                }
            }
            else if(multiplier == 100)
            {
                if(rem == 4)
                {
                    ans.push_back('D');
                    ans.push_back('C');
                }
                else if(rem == 9)
                {
                    ans.push_back('M');
                    ans.push_back('C');
                }
                else if(rem < 4)
                {
                    while(rem--)
                    {
                        ans.push_back('C');
                    }
                }
                else if(rem >= 5)
                {
                    int toAdd = rem - 5;
                    while(toAdd)
                    {
                        ans.push_back('C');
                        toAdd--;
                    }
                    ans.push_back('D');
                }
            }
            else if(multiplier == 1000)
            {
                while(rem--)
                {
                    ans.push_back('M');
                }
            }
            multiplier *= 10;
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};