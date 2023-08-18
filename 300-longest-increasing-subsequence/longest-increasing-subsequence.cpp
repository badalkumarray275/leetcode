class Solution {

    private:
    int f(int ind,int prevind,vector<int>& nums,int n,vector<vector<int>>& dp)
    {
        if(ind ==n) return 0;
        if(dp[ind][prevind+1] != -1) return dp[ind][prevind +1];
        int  len = 0 + f(ind+1,prevind,nums,n,dp);
        if(prevind == -1 || nums[ind] > nums[prevind])
         len =  max(len , 1 + f(ind+1,ind,nums,n,dp));
        
        return dp[ind][prevind+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return f(0,-1,nums,n,dp);

         vector<int>front(n+1,0);
         vector<int>curr(n+1,0);

        for(int ind =n-1;ind>=0;ind--)
        {
            for(int prev_ind =ind-1;prev_ind>=-1;prev_ind--)
            {
                 int  len = 0 + front[prev_ind+1];
                 if(prev_ind == -1 || nums[ind] > nums[prev_ind])
                   len =  max(len , 1 + front[ind+1]);
        
                curr[prev_ind+1] = len;
            }
            front = curr;
        }
        return front[0];
    }
};