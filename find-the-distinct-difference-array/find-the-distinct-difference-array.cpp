class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        int n = nums.size();
         vector<int>res(n);
         vector<int>pref(n);
         vector<int>suff(n);
         vector<int>unq1(51);
         vector<int>unq2(51);
        
        for(int i=0;i<n;i++)
        {
            unq1[nums[i]]++;
            if(unq1[nums[i]]==1)
                pref[i] =1;
            if(i)
            {
                pref[i] += pref[i-1];
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            unq2[nums[i]]++;
            if(unq2[nums[i]]==1)
                suff[i] =1;
            if(i<n-1)
            {
                suff[i] += suff[i+1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int left = pref[i];
            if((i+1)<n)
            {
                left -= suff[i+1];
            }
            res[i] = left;
        }
        return res;
        
        
    }
};