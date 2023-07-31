class Solution {
    private:
    int f(int n,vector<int>& dp)
    {
        if(n<=1) return 1;

        if(dp[n]!=-1) return dp[n];
        return dp[n] = f(n-1,dp)+f(n-2,dp);
    }
public:
    int climbStairs(int n) {
        // --> recursion approach

        // if(n==0) return 1;
        // if(n==1) return 1;
        // int left =  climbStairs(n-1);
        // int right = climbStairs(n-2);
        // return left+right;
  
    //  ---> memoization
        
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};