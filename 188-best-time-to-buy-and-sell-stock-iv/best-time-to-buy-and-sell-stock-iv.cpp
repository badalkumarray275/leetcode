class Solution {
    private:
       int f(int ind,int tran,vector<int>& prices,int n,vector<vector<int>>& dp,int k)
    {
        if(ind == n || tran == 2*k) return  0;
        if(dp[ind][tran] != -1) return dp[ind][tran];
        if(tran %2 ==0)
        {
            return dp[ind][tran] =  max(-prices[ind] + f(ind+1,tran+1,prices,n,dp,k) 
            , 0 + f(ind+1,tran,prices,n,dp,k));
        }
        
        return dp[ind][tran] =  max(prices[ind] + f(ind+1,tran+1,prices,n,dp,k) 
         , 0 + f(ind+1,tran,prices,n,dp,k));
    }  
public:
    int maxProfit(int k, vector<int>& prices) {

         int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        // return f(0,0,prices,n,dp,k);
       vector<int>after(2*k+1,0),curr(2*k+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tran =2*k-1;tran>=0;tran--)
            {
                 if(tran %2 ==0)
                 {
                    curr[tran] =  max(-prices[ind] + after[tran+1]
                    , 0 + after[tran]);
                  }
                 else

                  curr[tran] =  max(prices[ind] + after[tran+1]
                   , 0 + after[tran]);
            }
            after = curr;
        }

        return after[0];
    }
};