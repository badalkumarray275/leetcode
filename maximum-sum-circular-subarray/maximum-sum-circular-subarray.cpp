class Solution {
public:
    int maxsubarraysumnormal(vector<int>& nums)
    {
        int n =nums.size();
        int res =nums[0];
        int maxending = nums[0];
        for(int i=1;i<n;i++)
        {
            maxending = max(maxending+nums[i],nums[i]);
            res = max(res,maxending);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
      int max_normal = maxsubarraysumnormal(nums);
      if(max_normal<0)
        return max_normal;
      int n = nums.size();
      int nums_sum = 0;
      for(int i=0;i<n;i++)
      {
          nums_sum += nums[i];
          nums[i] = -nums[i];
      } 
      int max_circular = nums_sum + maxsubarraysumnormal(nums);
      return max(max_circular,max_normal);
    }
};