class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int nearsum =  nums[0]+ nums[1]+nums[2];

        for(int i=0;i<n-2;i++)
        {
            int low = i+1;
            int high = n-1;
            while(low<high)
            {
                int currsum = nums[i] + nums[low] + nums[high];
                if(abs(currsum-target)<abs(nearsum-target))
                {
                    nearsum = currsum;
                }
                if(currsum<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return nearsum;
    }
};