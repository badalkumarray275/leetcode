class Solution {
private:

bool subsetSumToK(int n, int k, vector<int> &arr) {
   
      vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int ind =0;ind<n;ind++)
        {
             dp[ind][0] = true;
         }
        
       if(arr[0]<=k) dp[0][arr[0]]  = true;
        for(int ind =1;ind<n;ind++)
        {
            for(int target =1;target<= k;target++)
            {
                  
              bool notpick = dp[ind-1][target];
              bool pick = false;
              if(target>=arr[ind]) pick = dp[ind-1][target-arr[ind]];
         
                dp[ind][target] = pick | notpick;     
            }
        }
        return dp[n-1][k];
    


}
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
       
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += nums[i];
	}

	if(sum %2 !=0) return false;

	int target  = sum/2;

    return   subsetSumToK(n,target,nums); 

    }
};