class Solution {
public:

   void solve(int i, vector<int>&op, vector<vector<int>>&res,vector<int>& nums)
   {
       if(i>=nums.size())
       {
           res.push_back(op);
           return;
       }
           op.push_back(nums[i]);
       solve(i+1,op,res,nums);
       op.pop_back();
       solve(i+1,op,res,nums);
  
       return;

   }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>res;
        vector<int>op;
        
        solve(0,op,res,nums);
        return res;

    }
};