class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(),s.end());
        int n = s.size();
        int i=0,j=0,lastIndex =0;
        while(j<n)
        {
            while(j<n && s[j]==' ')
            {
                j++;
            }
            int startIndex = i;
            while(j<n && s[j] != ' ')
            {
                s[i++] = s[j++];
                lastIndex =i;
            }
            reverse(s.begin()+startIndex,s.begin()+lastIndex);
            s[i++] =' ';
        }
        s.resize(lastIndex);
        return s;
    }
};