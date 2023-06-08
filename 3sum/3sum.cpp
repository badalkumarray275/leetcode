class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i =0;i<n-2;i++)
        {
            int low= i+1,high = n-1;
            while(low<high)
            {
               if(nums[i]+ nums[low]+nums[high]<0)
               {
                    low++;
               }
               else if(nums[i]+nums[low]+nums[high]>0)
               {
                      high--;
               } 
               else
               {
                     res.push_back({nums[i],nums[low],nums[high]});
                     int i =low,j = high;
                     while(low<high && nums[low]==nums[i]){ low++;}
                     while(low<high && nums[high]==nums[j]){high--;}
               }
            }
            while(i+1<n && nums[i]==nums[i+1])
            { i++; }
        }
        return res;
    }
};