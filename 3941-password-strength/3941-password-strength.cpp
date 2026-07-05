class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> s;
        int count = 0;
        for(char c: password)
        {
            if(c >= 'a' && c <= 'z' && !s.count(c))
            {
                count++;
                s.insert(c);
            }
            else if(c >= 'A' && c <= 'Z' && !s.count(c))
            {
                count += 2;
                s.insert(c);
            }
            else if(c >= '0' && c <= '9' && !s.count(c))
            {
                count += 3;
                s.insert(c);
            }
            else if((c == '!' || c == '@' || c == '#' || c == '$') && !s.count(c))
            {
                count += 5;
                s.insert(c);
            }
        }
        return count;
    }
};