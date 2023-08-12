class Solution {
public:
    bool canPartition(vector<int>& nums) {
        

          int n = nums.size();

          int t_sum =0;

          for(int i=0;i<n;i++)
          {
              t_sum += nums[i];
          }

          if(t_sum %2 != 0) return false;

          int sum = t_sum/2;

          vector<bool>prev(sum+1,0),curr(sum+1,0);

           prev[0]= curr[0] = 1;

          if(nums[0]<=sum) prev[nums[0]] =1;

          for(int ind =1;ind<n;ind++)
          {
              for(int target =1;target<=sum;target++)
              {
                  bool notpick = prev[target];
                  bool pick =false;

                  if(nums[ind]<=target)  pick = prev[target-nums[ind]];

                  curr[target] = notpick | pick;
              }
              prev = curr;
          }

          return prev[sum];
    }
};