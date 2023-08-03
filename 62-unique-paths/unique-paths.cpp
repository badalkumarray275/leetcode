class Solution {
    private:
    // int f(int row,int col, vector<vector<int>>& dp)
    // {
    //     if(row ==0 && col ==0)return 1;
    //     if(row <0 || col <0) return 0;

    //      int up = f(row-1,col,dp);
    //      int left = f(row,col-1,dp);

    //      return dp[row][col] = up + left;
    // }
public:
    int uniquePaths(int m, int n) {
        
    //     vector<vector<int>> dp(m,vector<int>(n,-1));

    //     // return f(m-1,n-1,dp);
       int mod = 2e9;
       
    //     for(int row=0;row<m;row++)
    //     {
    //         for(int col =0;col <n;col++)
    //         {
    //             if(row ==0 && col ==0) 
    //             {
    //                 dp[row][col] = 1;
    //             }   
    //                 else 
    //                 {
    //                     int up =0,left =0;
    //                     if(row>0)
    //                     {
    //                        up  += dp[row-1][col]; 
    //                     }
    //                     if(col >0)
    //                     {
    //                         left += dp[row][col-1];
    //                     }
    //                     dp[row][col] = (up + left)%mod;

    //                 }
                
    //         }
    //     }
    //     return (dp[m-1][n-1])%mod;
    //    int mod = 2e9;
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i ==0 && j==0)
                {
                   temp[j] =1;
                }
                else 
                {
                    int up =0,left =0;

                   if(i>0)
                   {
                       up = up+ prev[j];
                   }
                   if(j>0)
                   {
                       left = left + temp[j-1];
                   }
                   temp[j]  = ((left)%mod + (up)%mod)%mod;
                }
            }
            prev = temp;
        }
        return (prev[n-1])%mod;
    }
};