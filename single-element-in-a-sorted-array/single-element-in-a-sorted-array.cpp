class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int res = nums[0];
        for(int i=1;i<n;i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};