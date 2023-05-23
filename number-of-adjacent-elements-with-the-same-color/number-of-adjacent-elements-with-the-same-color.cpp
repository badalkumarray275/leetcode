class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        
        vector<int> a(n);
        vector<int> res;
        int c =0;
        for(auto &x: queries)
        {
            int idx = x[0];
            int col = x[1];
            
            if(a[idx]==col)
            {
                res.push_back(c);
            }
            else
            {
                int before =0;
                if((idx-1)>=0)
                {
                    if((a[idx] == a[idx-1])&& a[idx])
                    {
                        before++;
                        
                    }
                }
                if((idx+1)<n)
                {
                    if((a[idx]==a[idx+1])&&a[idx])
                    {
                        before++;
                    }
                }
                
                int after =0;
                a[idx] = col;
                
                 if((idx-1)>=0)
                {
                    if((a[idx] == a[idx-1])&& a[idx])
                    {
                        after++;
                        
                    }
                }
                if((idx+1)<n)
                {
                    if((a[idx]==a[idx+1])&&a[idx])
                    {
                        after++;
                    }
                }
                
               c += after - before;
                res.push_back(c);
            }
            
            
        }
        return res;
        
        
    }
};