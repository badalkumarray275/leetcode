class Solution {

private:
    bool matching(char a,char b)
    {
        return ((a == '(' && b == ')') 
        || (a == '{' && b == '}')
         || (a == '[' && b == ']'));
    }

public:
    bool isValid(string s) {
        
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
           if(s[i] == '(' || s[i] == '{' || s[i] == '[')
           {
              st.push(s[i]);
           }
           else
           {
               if(st.empty())
               {
                  return false;
               }
               else if(!matching(st.top(),s[i]))
              {
                 return false;
             }
             else
            {
               st.pop();
            }
         }
     }
       return (st.empty() == true);

    }
};