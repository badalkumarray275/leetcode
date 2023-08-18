class Solution {
        private:

    int f(int ind,int buy,vector<int>& prices, vector<vector<int>>& dp,int n)
    {
       
        if(ind >= n) return 0;
        
         if(dp[ind][buy]  != -1) return dp[ind][buy]; 
        if(buy)
        {
          return   dp[ind][buy] =   max(-prices[ind] + f(ind+1,0,prices,dp,n),(0 + f(ind+1,1,prices,dp,n)));

        }
        
        return   dp[ind][buy] = max( (prices[ind] + f(ind+2,1,prices,dp,n)), (0 + f(ind+1,0,prices,dp,n)));
        
    }  
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<int>>dp(n+2,vector<int>(2,0));

        // return f(0,1,prices,dp,n);
        vector<int>front2(2,0);
        vector<int>front1(2,0);
        vector<int>curr(2,0);


        for(int ind =n-1;ind>=0;ind--)
        {
            for(int buy =0;buy<2;buy++)
            {
                  if(buy)
                 {
                   curr[buy] =   max(-prices[ind] + front1[0],
                       0 + front1[1]);
 
                 }
                else

                 curr[buy] = max(prices[ind] + front2[1], 
                   0 + front1[0]);
            }
            front2 = front1;
            front1 = curr;
        }
        return front1[1];
    }
};