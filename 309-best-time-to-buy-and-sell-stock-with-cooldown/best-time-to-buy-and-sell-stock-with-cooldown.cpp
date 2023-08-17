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
        // vector<vector<int>>dp(n+2,vector<int>(2,0));
        // return f(0,1,prices,n,dp);
         vector<int>front2(2,0);
          vector<int>front1(2,0); 
          vector<int>curr(2,0);
        for(int ind =n-1;ind>=0;ind--)
        {
    
              curr[1] = max(-prices[ind] + front1[0]
                      , 0 + front1[1]);

                curr[0] = max(prices[ind] + front2[1]
                      , 0 + front1[0]);
                    
                front2 = front1;
                front1 = curr;
                 
            
        }
         return curr[1];
    }
};