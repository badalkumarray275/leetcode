class Solution {
public:
 
    string reverseWords(string s) {
        
        reverse(s.begin(),s.end());
        int i =0;
        int n = s.length();
        int j=0;
        int lastIndex =0;
        while(j<n)
        {
            while(j<n && s[j] == ' ')
            {
               j++;

            }
            int startIndex = i;
           while(j<n && s[j]!=' ')
           {
               s[i] = s[j];
               i++;
               j++;
               lastIndex = i;
           }

           reverse(s.begin()+startIndex ,s.begin()+lastIndex);
           s[i++] = ' ';

        }
    
      s.resize(lastIndex);
        return s;
    }
};