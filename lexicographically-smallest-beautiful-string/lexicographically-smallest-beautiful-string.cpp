class Solution {
public:
    
     bool isValid(string &s,int i)
    {
       return ((i<1 || s[i]!=s[i-1])&& (i<2 ||s[i]!=s[i-2])); 
    }
    string smallestBeautifulString(string s, int k) {
        
        for(int i=s.size()-1;i>=0;i--)
        {
            s[i]++;
            while(!isValid(s,i))
                s[i]++;
            if(s[i]<'a'+k)
            {
                for(int j=i+1;j<s.size();j++)
                {
                    s[j]='a';
                    while(!isValid(s,j))
                    {
                        s[j]++;
                    }
                }
                return s;
            }    
        }
        return "";
        
        
        
    }
};