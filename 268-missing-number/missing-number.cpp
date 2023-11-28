class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // --> brute
         int n  = nums.size();
        // for(int i=0;i<=n;i++)
        // {
        //     int flag = 0;
        //     for(int j =0;j<n;j++)
        //     {
        //         if(nums[j] == i)
        //         {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag == 0)
        //     {
        //         return i;
        //     }
        // }
        // return 0;
        

        // -->optimal

    //    vector<int>hash(n+1,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         hash[nums[i]] =1;

    //     }
    //     for(int i=1;i<=n;i++)
    //     {
    //         if(hash[i] !=1)
    //           return i;
    //     }
    //     return 0;

    //  --> better
        //   -->method1
        // int sum = n*(n+1)/2;
        // int s2=0;
        // for(int i=0;i<n;i++)
        // {
        //     s2 += nums[i];
        // }
        // return sum-s2;

    //  -->mehod2 and best method

         int xor1=0;
         int xor2 =0;
         for(int i=0;i<n;i++)
         {
             xor1 ^= (i+1);
             xor2 ^= nums[i];
         }
        
         return xor1^xor2;

    }
};