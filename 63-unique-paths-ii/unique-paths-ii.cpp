class Solution {

    private:
    int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int up = f(i-1,j,obstacleGrid,dp);
        int left = f(i,j-1,obstacleGrid,dp);

        return dp[i][j] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         
         int m = obstacleGrid.size();
         int n = obstacleGrid[0].size();
        //  vector<vector<int>> dp(m,vector<int>(n,-1));
        // //  return f(m-1,n-1,obstacleGrid,dp);
         int mod = 2e9;
        //  if(obstacleGrid[0][0] ==1) return 0;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0) 
        //         {
        //             dp[i][j] =1;

        //         }
        //         else if(obstacleGrid[i][j] ==1)
        //         {
        //             dp[i][j] =0;
        //         }
        //         else
        //         {
        //             int up =0,left =0;
        //             if(i>0)
        //             {
        //                 up += dp[i-1][j];
        //             }
        //             if(j>0)
        //             {
        //                 left += dp[i][j-1];
        //             }

        //             dp[i][j] = (up + left)%mod;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int>prev(n,0);
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) temp[j] =1;
                else if(obstacleGrid[i][j] ==1) temp[j] =0;
                else {
                  
                   int up = 0,left =0;
                   if(i>0) up += prev[j];
                   if(j>0)  left += temp[j-1];

                   temp[j] = (up + left)%mod;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};