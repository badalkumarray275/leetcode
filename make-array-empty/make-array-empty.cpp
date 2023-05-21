class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        
        
       long long res =0;
       int n = nums.size();
        vector<pair<int,int>> p;
       for(int i=0;i<n;i++)
       {
           p.push_back({nums[i],i});
       }
       
        sort(p.begin(),p.end());
        long long last =0;
        long long curr =n;
        long long d =0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                d=1;
                last = p[i].second;
                if(i==n-1)
                    res++;
            }
            else
            {
                if(p[i].second<last)
                {
                    res += curr;
                    curr -= d;
                    d =1;
                    last = p[i].second;
                    if(i==n-1)
                        res++;
                }
                else
                {
                    last = p[i].second;
                    d++;
                    if(i==n-1)
                      res += curr;
                    
                }
            }
        }
        return res;
        
    }
};