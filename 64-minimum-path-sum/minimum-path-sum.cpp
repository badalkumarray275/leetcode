class Solution {
    private:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
       
         if(i==0 && j==0) return grid[i][j];
         if(i<0 || j<0) return 1e9;
         
         if(dp[i][j] !=-1) return dp[i][j];

         int up =  grid[i][j] + f(i-1,j,grid,dp);
         int left = grid[i][j] + f(i,j-1,grid,dp);

         return  dp[i][j] = min(up ,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
         
         int m = grid.size();
         int n = grid[0].size();
        //  vector<vector<int>> dp(m,vector<int>(n,-1));

        //  return f(m-1,n-1,grid,dp);

        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0) dp[i][j] = grid[i][j];
        //         else
        //         {
        //             int up =0,left =0;
        //             if(i>0) up += grid[i][j] + dp[i-1][j];
        //             else up += 1e9;
        //             if(j>0) left += grid[i][j] + dp[i][j-1];
        //             else left += 1e9;

        //             dp[i][j] = min(up,left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int>prev(n,0);

        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
               if(i==0 && j==0) temp[j] = grid[i][j];
               else
               {
                   int up=0,left=0;
                   if(i>0) up += grid[i][j] + prev[j];
                   else up += 1e9;
                   if(j>0) left += grid[i][j] + temp[j-1];
                   else left +=  1e9;

                   temp[j] = min(up,left);
               }
            }
            prev = temp;
        }
       
       return prev[n-1];
    }
};