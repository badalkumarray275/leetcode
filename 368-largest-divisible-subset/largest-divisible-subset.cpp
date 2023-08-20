class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,1),hash(n);
         sort(nums.begin(),nums.end());
        int maxi  =1;
        int lastIndex = 0;

        for(int ind=0;ind<n;ind++)
        {
            hash[ind] = ind;
            for(int prev =0;prev<ind;prev++)
            {
                if(nums[ind] % nums[prev] ==0 && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind]>maxi)
            {
                maxi = dp[ind];
                lastIndex = ind;
            }
        }

        vector<int>ans;
        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
        

    }
};