class Solution {
   private:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        int n = matrix.size();
        if(j<0 || j>=n) return 1e9;
        if(i==0) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];

        int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
        int up = matrix[i][j] + f(i-1,j,matrix,dp);
        int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);

        return dp[i][j] = min(ld,min(up,rd));

    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini = 1e9;
        // for(int j=0;j<n;j++)
        // {
        //      mini = min(mini,f(n-1,0,matrix,dp));
        // }
        // return mini;
        

        // for(int j=0;j<n;j++)
        // {
        //     dp[0][j] = matrix[0][j];
        // }

        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         int ld =0,up =0,rd=0;
        //       if(j-1>=0)  ld += matrix[i][j] + dp[i-1][j-1];
        //          else ld += 1e9;
        //         up += matrix[i][j] + dp[i-1][j];
        //      if(j+1<n)  rd += matrix[i][j] + dp[i-1][j+1];
        //          else rd += 1e9;
             
        //       dp[i][j] = min(ld,min(up,rd));
              
               

        //     }
        // }
        // for(int j=0;j<n;j++)
        // {
        //     mini = min(mini,dp[n-1][j]);
        // }
        // return mini;

        vector<int>prev(n,0);

        for(int j=0;j<n;j++)
        {
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;j++)
            {
                int ld =0,up =0,rd=0;
              if(j-1>=0)  ld += matrix[i][j] + prev[j-1];
                 else ld += 1e9;
                up += matrix[i][j] + prev[j];
             if(j+1<n)  rd += matrix[i][j] + prev[j+1];
                 else rd += 1e9;
             
             curr[j] = min(ld,min(up,rd));
              

            }
            prev = curr;
        }
        for(int j=0;j<n;j++)
         {
            mini = min(mini,prev[j]);
        }
        return mini;
    }
};