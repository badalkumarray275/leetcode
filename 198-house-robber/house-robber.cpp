class Solution {

long long int f(vector<int>& nums)
{
    long long int prev = nums[0];
    long long int  prev2 = 0;
    long long int n = nums.size();

    
    for(long long int i=1;i<n;i++)
    {
        long long int take = nums[i];
        if(i>1)
        {
            take += prev2;
        }
        long long int nontake = 0 + prev;
        long long int curr = max(take,nontake);
        
        prev2 = prev;
        prev =curr;
    }
    return prev;
}
public:
    int rob(vector<int>& nums) {
       
    long long int n = nums.size();
    if(n==1) return nums[0];

       return f(nums);
    }
};