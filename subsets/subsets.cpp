class Solution {
public:

void solve(vector<int>nums,vector<vector<int>> &ans,vector<int>op,int index)
{
    if(index>=nums.size())
    {
        ans.push_back(op);
        return;
    }
    solve(nums,ans,op,index+1);
      op.push_back(nums[index]);
    solve(nums,ans,op,index+1);
    return;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int>op;
        int index =0;
        solve(nums,ans,op,index);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};