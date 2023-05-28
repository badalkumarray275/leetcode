class Solution {
public:
  
    void solve(string ip,string op,vector<string>&res)
    {
        if(ip.length()==0)
        {
            res.push_back(op);
            return;
        }

        if(isalpha(ip[0]))
        {
            string op1 =op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin()+0);
            solve(ip,op1,res);
            solve(ip,op2,res);

        }
        else
        {
            string op3 = op;
            op3.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op3,res);

            
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string>res;
        string ip = s;
        string op ="";
        solve(ip,op,res);
        return res;
    }
};