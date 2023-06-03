class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res =0;
        int n = nums.size();
        int psum[n];
        psum[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            psum[i] = nums[i]+ psum[i-1];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(psum[i]==k)
               res++;
            if(mp.find(psum[i]-k) != mp.end()) 
               res += mp[psum[i]-k];  
        
             mp[psum[i]]++;
        }
        return res;     
    }
};