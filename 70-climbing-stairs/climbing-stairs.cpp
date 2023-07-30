class Solution {
public:

    int climbStairs(int n) {

    //    int prev2 =1;
    //    int prev =1;
    //    for(int i=2;i<=n;i++)
    //    {
    //      int   curr = prev + prev2;
    //        prev = curr;
    //        prev2 = prev;
    //    } 
    //    return prev;
    vector<int>dp(n+1,-1);
    dp[0] =1;
    dp[1] =1;

    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
       
    }
};