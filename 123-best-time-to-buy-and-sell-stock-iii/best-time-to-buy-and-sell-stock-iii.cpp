class Solution {

    int f(int ind,int tran,vector<int>& prices,int n,vector<vector<int>>& dp)
    {
        if(ind == n || tran == 4) return  0;
        if(dp[ind][tran] != -1) return dp[ind][tran];
        if(tran %2 ==0)
        {
            return dp[ind][tran] =  max(-prices[ind] + f(ind+1,tran+1,prices,n,dp) 
            , 0 + f(ind+1,tran,prices,n,dp));
        }
        
        return dp[ind][tran] =  max(prices[ind] + f(ind+1,tran+1,prices,n,dp) 
         , 0 + f(ind+1,tran,prices,n,dp));
    }   
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,prices,n,dp);
    }
};