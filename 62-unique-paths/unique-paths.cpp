class Solution {
    private:
    int f(int i,int j, vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] !=-1) return dp[i][j];
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);

        return dp[i][j] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // //   return f(m-1,n-1,dp);

        // // dp[0][0] = 1;
        int mod = 2e9;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0) 
        //         {
        //             dp[0][0] =1;
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
        // return (dp[m-1][n-1])%mod;
        vector<int> prev(n,0);

        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[0] =1;
                }
                else 
                {
                    int up = 0,left =0;

                    if(i>0) 
                    {
                        up += prev[j];
                    }
                    if(j>0)
                    {
                        left += temp[j-1];
                    }

                    temp[j] = (up + left)%mod;
                }
            }
            prev = temp;
        }
        return (prev[n-1])%mod;
    }
};