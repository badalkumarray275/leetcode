class Solution {
public:

   bool isSafe(int row,int col,vector<vector<int>>& board,int n)
   {
       for(int i=0;i<n;i++)
       {
           if(board[row][i]== 1)
           {
               return false;
           }
       }
       for(int i=row,j= col;i>=0 && j>=0 ;i--,j--)
       {
          if(board[i][j]==1)
          {
              return false;
          }
       }
       for(int i=row,j=col;i<n && j>=0;i++,j--)
       {
           if(board[i][j]==1)
           {
               return false;
           }
       }
       return true;
   }
   void solve(int col,vector<vector<int>> & board,vector<vector<int>>& res,int n,int &count)
   {
       if(col == n)
       {
           count++;
           return ;
       }
       for(int i=0;i<n;i++)
       {
           if(isSafe(i,col,board,n))
           {
               board[i][col] =1;
               solve(col+1,board,res,n,count);
               board[i][col] = 0;
             }              
       }
   }
    int totalNQueens(int n) {
        
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>res;
        int count =0;
        solve(0,board,res,n,count);
        return count;
    }
};