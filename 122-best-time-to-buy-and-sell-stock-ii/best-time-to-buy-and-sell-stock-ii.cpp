class Solution {
    private:

    int f(int ind,int buy,vector<int>& prices, vector<vector<int>>& dp,int n)
    {
       
        if(ind == n) return 0;
         int profit =0;
         if(dp[ind][buy]  !=-1) return dp[ind][buy]; 
        if(buy)
        {
           profit =  max(-prices[ind] + f(ind+1,0,prices,dp,n),(0 + f(ind+1,1,prices,dp,n)));

        }
        else
        {
            profit = max( (prices[ind] + f(ind+1,1,prices,dp,n)), (0 + f(ind+1,0,prices,dp,n)));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        
           int n = prices.size();
           vector<vector<int>>dp(n+1,vector<int>(2,0));
        //    return f(0,1,prices,dp,n);

          dp[n][0] =0;
          dp[n][1] =0;

          for(int ind =n-1;ind>=0;ind--)
          {
              for(int buy=0;buy<2;buy++)
              {
                    int profit =0;
                     if(buy)
                    {
                          profit =  max(-prices[ind] + dp[ind+1][0],0 + dp[ind+1][1]);

                     }
                    else
                      {
                         profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                      }
                      dp[ind][buy] = profit;
              }
          }
          return dp[0][1];

    }
};