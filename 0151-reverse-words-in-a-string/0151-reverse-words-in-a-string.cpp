class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string res = "";
        for(char c: s)
        {
            if(c == ' ' && !res.empty())
            {
                st.push(res);
                res.clear();
            }
            else if(c != ' ')
                res += c;
        }
        if(!res.empty())
            st.push(res);
        string result;
        while(!st.empty())
        {
            result += st.top();
            st.pop();
            if(!st.empty())
                result += " ";
        }
        return result;
    }
};