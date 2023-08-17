class Solution {
    private:
    int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>& dp)
    {
       if(ind == n ||  cap ==0) return 0;
        
        if(dp[ind][buy][cap] !=-1) return dp[ind][buy][cap];
        if(buy)
        {
            return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp), 
            0 + f(ind+1,1,cap,prices,n,dp));
        }
         
         return dp[ind][buy][cap] =  max(prices[ind] + f(ind +1,1,cap-1,prices,n,dp) ,
         0 + f(ind+1,0,cap,prices,n,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return f(0,1,2,prices,n,dp);

        // for(int buy = 0;buy<2;buy++)
        // {
        //     for(int cap = 0;cap<3;cap++)
        //     {
        //          dp[n][buy][cap] = 0;
        //     }
        // }

        // for(int ind=0;ind<n;ind++)
        // {
        //     for(int buy =0;buy<2;buy++)
        //     {
        //         dp[ind][buy][0] = 0;
        //     }
        // }
       vector<vector<int>>prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy =0;buy<2;buy++)
            {
                for(int cap =1;cap<3;cap++)
                {
                     if(buy)
                     {
                       curr[buy][cap] = max(-prices[ind] + prev[0][cap], 
                       0 + prev[1][cap]);
                     }
                     else
         
                     curr[buy][cap] =  max(prices[ind] + prev[1][cap-1],
                     0 + prev[0][cap]);
                }
            }
            prev = curr;
        }
        return prev[1][2];
    }
};