class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n,vector<int>(n));
        int top =0,bottom =n-1;
        int left =0,right =n-1;
        int a =1;
        while(top<=bottom && left<=right)
        {
            for(int i= left;i<=right;i++)
            {
                res[top][i] = a;
                a++;
            }
            top++;
            for(int i = top;i<=bottom;i++)
            {
                res[i][right]= a;
                a++;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    res[bottom][i]=a;
                    a++;
                }
               bottom--;
            }

            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res[i][left]=a;
                    a++;
                }
               left++;
            }
              

        }
        return res;
    }
};