class Solution {

    private:
     int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>& dp)
     {
         if(ind == n || cap ==0) return 0;
         
         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
         if(buy) 
         {
              return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp) ,
               0 + f(ind+1,1,cap,prices,n,dp));
         }
         return dp[ind][buy][cap] =  max( prices[ind] + f(ind+1,1,cap-1,prices,n,dp) ,
          0 + f(ind+1,0,cap,prices,n,dp));
     }
public:
    int maxProfit(vector<int>& prices) {
        

        int n = prices.size();
        vector<vector<int>> front(2,vector<int>(3,0));
          vector<vector<int>>curr(2,vector<int>(3,0));
        // return f(0,1,2,prices,n,dp);

  
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy =0;buy<2;buy++)
            {
                for(int cap =1;cap<3;cap++)
                {
                     if(buy) 
                   {
                       curr[buy][cap] = max(-prices[ind] + front[0][cap],
                     0 + front[1][cap]);
                   }
                   else

                      curr[buy][cap] =  max( prices[ind] + front[1][cap-1], 
                     0 + front[0][cap]);
                }
            }
            front = curr;
        }
         return front[1][2];
        
    }
};