class Solution {
    private:
    int f(int ind,int buy,vector<int>& prices,int n, vector<vector<int>>& dp)
    {
        if(ind >= n) return 0;
          
          if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,n,dp)
             , 0 + f(ind+1,1,prices,n,dp));
        }
        return  dp[ind][buy] = max(prices[ind] + f(ind+2,1,prices,n,dp) 
          , 0 + f(ind+1,0,prices,n,dp));

    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // return f(0,1,prices,n,dp);

        for(int ind =n-1;ind>=0;ind--)
        {
            for(int buy =0;buy<2;buy++)
            {
                 if(buy)
                  {
                       dp[ind][buy] = max(-prices[ind] + dp[ind+1][0]
                      , 0 + dp[ind+1][1]);
                    }
                    else
                    {
                         dp[ind][buy] = max(prices[ind] + dp[ind+2][1]
                      , 0 + dp[ind+1][0]);
                    }  
            }
        }
         return dp[0][1];
    }
};