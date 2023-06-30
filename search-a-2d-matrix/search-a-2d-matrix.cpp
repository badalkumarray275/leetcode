class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i=0,j= matrix[0].size()-1;
        while(i<matrix.size() && j>=0)
        {
            if(target<matrix[0][0])
            {
                return false;
            }
            if(target>matrix[matrix.size()-1][matrix[0].size()-1])
            {
                return false;
            }
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
          return false;
    }
 
};