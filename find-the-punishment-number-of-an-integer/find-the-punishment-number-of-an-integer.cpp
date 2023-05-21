class Solution {
public:
    int punishmentNumber(int n) {
        
        int res =0;
        for(int i=1;i<=n;i++)
        {
            int val = i*i;
            string temp = to_string(val);
            int f =0;
            int sz = temp.size();
            
            
            for(int j=1;j<(1<<sz) ;j++)
            {
                int sum =0;
                int total =0;
                
                for(int k =0;k<sz;k++)
                {
                    if(j&(1<<k))
                    {
                        total += sum;
                        
                        sum = (temp[k]-'0');
                        
                    }
                    else
                    {
                        sum *= 10;
                        sum += (temp[k]-'0');
                        
                        
                    }
                }
                total += sum;
                if(total == i)
                {
                    f =1;
                    break;
                    
                }
                
            }
            if(f)
            {
                res += val;
            }
                
            
        }
        return res;
        
        
        
    }
};