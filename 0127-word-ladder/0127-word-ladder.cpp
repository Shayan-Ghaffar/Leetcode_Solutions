class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
                q.pop();
                if(check.first == endWord)
                    return check.second;
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
        return 0;
    }
};