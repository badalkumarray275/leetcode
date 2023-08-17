class Solution {
   
   private:
    int f(int ind,int buy,vector<int>& prices, vector<vector<int>>& dp,int n,int fee)
    {
       
        if(ind == n) return 0;
         int profit =0;
         if(dp[ind][buy]  !=-1) return dp[ind][buy]; 
        if(buy)
        {
           profit =  max(-prices[ind] + f(ind+1,0,prices,dp,n,fee),
           (0 + f(ind+1,1,prices,dp,n,fee)));

        }
        else
        {
            profit = max( (prices[ind] - fee + f(ind+1,1,prices,dp,n,fee)),
             (0 + f(ind+1,0,prices,dp,n,fee)));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         
           int n = prices.size();
        //    vector<vector<int>>dp(n+1,vector<int>(2,0));
        //    return f(0,1,prices,dp,n);
        
        // vector<int>ahead(2,0),curr(2,0);
          int aheadNotBuy =0;
          int   aheadBuy  =0;
 
          for(int ind =n-1;ind>=0;ind--)
          {
              for(int buy=0;buy<2;buy++)
              {
                   
                   int currNotBuy = max(prices[ind] + aheadBuy ,0 +aheadNotBuy);
                   int  currBuy = max(-prices[ind] -fee +  aheadNotBuy,0+aheadBuy);
                   aheadNotBuy = currNotBuy;
                   aheadBuy = currBuy;
              }
            
          }
          return aheadBuy;

    }
};