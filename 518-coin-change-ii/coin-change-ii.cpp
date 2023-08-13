class Solution {

 private:

 int f(int ind,int target,vector<int>& coins,vector<vector<int>>& dp)   
 {
     if(ind == 0)
     {
         return target % coins[0] == 0;
     }

     int notpick = f(ind-1,target,coins,dp);
     int pick = 0;

     if(coins[ind] <= target) pick = f(ind,target-coins[ind],coins,dp);

     return dp[ind][target] = notpick + pick;

 }
public:
    int change(int amount, vector<int>& coins) {
        
         int n = coins.size();

        //  vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //  return f(n-1,amount,coins,dp);
   
        vector<int>prev(amount+1,0),curr(amount+1,0);

       for(int target =0;target<=amount;target++)
       {
               prev[target] = (target % coins[0] == 0);
       }

       for(int ind =1;ind<n;ind++)
       {
           for(int target=0;target<=amount;target++)
           {
               
                 int notpick = prev[target];
                 int pick = 0;

               if(coins[ind] <= target) pick = curr[target-coins[ind]];

               curr[target] = notpick + pick;
           }
           prev = curr;
       }
           return prev[amount];
    }
};