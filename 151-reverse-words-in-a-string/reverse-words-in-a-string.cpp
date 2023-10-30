class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(),s.end());
        int i=0,j=0;
        int last =0;
        int n = s.size();
        while(j<n)
        {
            while(j<n && s[j] ==' ')
            {
                j++;
            }
            int start =i;
            while(j<n && s[j] != ' ')
            {
                s[i++] = s[j++];
                last = i;
            }

            reverse(s.begin()+start,s.begin()+last);
            s[i++] = ' ';
        }
        s.resize(last);
        return s;
    }
};