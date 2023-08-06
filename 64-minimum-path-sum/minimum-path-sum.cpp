class Solution {
private:
    int f(int row,int col ,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(row ==0 && col ==0) return grid[0][0];
        if(row <0 || col<0) return 1e9;
       
        if(dp[row][col] !=-1) return dp[row][col];
        int up = grid[row][col] + f(row-1,col,grid,dp);
        int left = grid[row][col] + f(row,col-1,grid,dp);

       return dp[row][col] = min(up,left);
    }    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid,dp);

        // for(int row =0;row<m;row++)
        // {
        //     for(int col =0;col<n;col++)
        //     {
        //         if(row ==0 && col ==0) dp[row][col] = grid[0][0];
        //         else
        //         {
        //             int up =0,left =0;
        //             if(row-1>=0) up += grid[row][col] + dp[row-1][col];
        //             else up += 1e9;
        //             if(col-1>=0) left += grid[row][col] + dp[row][col-1];
        //             else left += 1e9;

        //             dp[row][col] = min(up,left); 
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int>prev(n,0);

        for(int row=0;row<m;row++)
        {
            vector<int>temp(n,0);
            for(int col =0;col<n;col++)
            {
                if(row ==0 && col ==0) temp[col] = grid[0][0];
                else
                {
                    int up =0,left =0;
                    if(row-1>=0) up += grid[row][col] + prev[col];
                    else up += 1e9;
                    if(col-1>=0) left += grid[row][col] + temp[col-1];
                    else left += 1e9;

                   temp[col] = min(up,left); 
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};