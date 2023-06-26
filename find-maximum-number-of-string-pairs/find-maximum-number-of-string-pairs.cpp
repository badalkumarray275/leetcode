class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int res =0;
        unordered_set<string>used;
        unordered_set<string>all;
        
        for(const string& word : words)
        {
            all.insert(word);
            
        }
        for(const string& word : words)
        {
            if(used.count(word))
            {
                continue;
            }
            string rev = word;
            reverse(rev.begin(),rev.end());
            if(all.count(rev) && !used.count(rev) && rev != word)
            {
                res++;
                used.insert(rev);
                used.insert(word);
            }
        }
        return res;
    }
};