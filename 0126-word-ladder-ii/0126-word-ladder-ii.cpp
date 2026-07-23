class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mpp;
    string b;
    int N;
public:
    void dfs(string word, vector<string> seq)
    {
        if(b == word)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        for(int j = 0; j < N;j++)
        {
            int size = mpp[word];
            char original = word[j];
            for(char ch = 'a'; ch <= 'z';ch++)
            {
                word[j] = ch;
                if(mpp.count(word) > 0)
                {
                    if(mpp[word] + 1 == size)
                    {
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
            }
            word[j] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        N = beginWord.length();
        queue<pair<string, int>> q;
        unordered_set<string> set(wordList.begin(), wordList.end());
        set.erase(beginWord);
        int steps = 1;
        q.push({beginWord, steps});
        int length = beginWord.length();
        while(!q.empty())
        {
            int N = q.size();
            for(int i = 0; i < N;i++)
            {
                pair<string, int> check = q.front();
                mpp[check.first] = check.second;
                q.pop();
                if(check.first == endWord)
                    break;
                string word = check.first;
                for(int j = 0; j < length;j++)
                {
                    char original = word[j];
                    for(char ch = 'a'; ch <= 'z';ch++)
                    {
                        word[j] = ch;
                        if(set.count(word))
                        {
                            set.erase(word);
                            q.push({word, steps+1});
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }
        b = beginWord;
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
        return ans;
    }
};