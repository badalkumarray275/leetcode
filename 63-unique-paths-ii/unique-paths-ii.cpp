class Solution {
private:
int f(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)  
{
    if(row>=0 && col>=0 && obstacleGrid[row][col]==1) return 0;
    if(row==0 && col ==0) return 1;
    if(row<0 || col<0) return 0;
     
     if(dp[row][col] != -1) return dp[row][col];
    int up = f(row-1,col,obstacleGrid,dp);
    int left = f(row,col-1,obstacleGrid,dp);

    return  dp[row][col] = up + left;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // return f(m-1,n-1,obstacleGrid,dp);
       
    //    for(int row=0;row<m;row++)
    //    {
    //        for(int col =0;col<n;col++)
    //        {
    //             if(obstacleGrid[row][col]==1) dp[row][col] = 0;
    //             else  if(row==0 && col ==0) dp[row][col] = 1;
    //             else
    //             { int up =0,left =0;
    //               if(row-1>=0)  up += dp[row-1][col];
    //               if(col-1>=0) left += dp[row][col-1];

    //                dp[row][col] = up + left;
    //             }
    //        }
    //    }
    //    return dp[m-1][n-1];

        vector<int>prev(n,0);
        
        for(int row=0;row<m;row++)
        {
            vector<int>temp(n,0);
            for(int col =0;col<n;col++)
            {
                
                if(obstacleGrid[row][col]==1) temp[col] = 0;
                else  if(row==0 && col ==0) temp[col] = 1;
                else
                { int up =0,left =0;
                  if(row-1>=0)  up += prev[col];
                  if(col-1>=0) left += temp[col-1];

                   temp[col] = up + left;
                }  
            }
            prev = temp;
        }

        return prev[n-1];

    }
};