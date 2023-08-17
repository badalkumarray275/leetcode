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
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return f(0,0,prices,n,dp,k);
    }
};