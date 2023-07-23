class Solution {
private:
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string> &seq)
    {
        if(word == b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return
            ;
        }
         int steps = mp[word]; 
        int sz = word.size();
        for(int i=0;i<sz;i++)
        {
            char original = word[i];
            for(char ch ='a';ch<='z';ch++)
            {
                word[i]= ch;
                if(mp.find(word)!=mp.end() && mp[word] + 1 == steps)
                {
                     seq.push_back(word);
                     dfs(word,seq);
                     seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
  public:  
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push({beginWord});
        mp[beginWord] = 1;
        set<string>s(wordList.begin(),wordList.end());
        s.erase({beginWord});
        b = beginWord;
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int steps = mp[word];

            int sz = word.size();
            for(int i=0;i<sz;i++)
            {
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(s.find(word)!=s.end())
                    {
                        q.push({word});
                        s.erase(word);
                        mp[word] = steps +1;
                    }
                }
                word[i] = original;
            } 
            
        }
        
        if(mp.find(endWord) != mp.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};