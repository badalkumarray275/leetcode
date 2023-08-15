class Solution {
    private:

    int f(int ind,int target,vector<int>& coins, vector<vector<int>>& dp)
    {
        if(ind ==0) 
        {
            if((target % coins[0]) ==0) return  target/coins[0];
            else return 1e9;
        }
           if(dp[ind][target] != -1) return dp[ind][target];
        int notpick = 0 + f(ind-1,target,coins,dp);
        int pick =  INT_MAX;

        if(coins[ind]<=target) pick = 1 + f(ind,target-coins[ind],coins,dp);

        return dp[ind][target] = min(notpick,pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans =  f(n-1,amount,coins,dp);
       
       vector<int>prev(amount+1,0);
       for(int  target =0;target<=amount;target++)
       {
           if((target%coins[0])==0) prev[target] = target/coins[0];
           else prev[target] = 1e9;
       }


       for(int ind =1;ind<n;ind++)
       {
           for(int  target =0;target<=amount;target++)
           {
                  int notpick = 0 + prev[target];
                  int pick =  INT_MAX;

                  if(coins[ind]<=target) pick = 1 + prev[target-coins[ind]];

                  prev[target] = min(notpick,pick);
           }
          
       }
       int ans = prev[amount];
        if(ans != 1e9) return ans;
        else return -1;
    }
};