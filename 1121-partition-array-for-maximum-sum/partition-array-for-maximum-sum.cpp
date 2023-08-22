class Solution {

   private:
       int f(int ind,vector<int>& arr, int k,vector<int> &dp)
       {
           int n = arr.size();
           if(ind ==n) return 0;
           if(dp[ind] != -1) return dp[ind];
            int len =0;
            int maxsum =0;
            int maxi =  INT_MIN;
           for(int j =ind;j<min(n,ind+k);j++)
           {
                len++;
                maxi = max(maxi,arr[j]);
                 int   sum = len*maxi + f(j+1,arr,k,dp);
                maxsum = max(maxsum,sum);
           }
           return dp[ind] = maxsum;
       }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>dp(n+1,0);
        // return f(0,arr,k,dp);

        dp[n] =0;

        for(int ind = n-1;ind>=0;ind--)
        {
            int len =0;
            int maxsum =0;
            int maxi =  INT_MIN;
           for(int j =ind;j<min(n,ind+k);j++)
           {
                len++;
                maxi = max(maxi,arr[j]);
                 int   sum = len*maxi + dp[j+1];
                maxsum = max(maxsum,sum);
           }
             dp[ind] = maxsum;
        }
        return dp[0];
    }
};