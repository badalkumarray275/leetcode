class Solution {
public:
 bool isSafe(int row,int col,vector<string>& board,int n)
 {
     for(int i=0;i<col;i++)
     {
         if(board[row][i]=='Q')
         {
             return false;
         }
     }
     for(int i=row,j=col;i>=0 && j>=0; i--,j--)
     {
         if(board[i][j]=='Q')
         {
             return false;
         }
     }
     for(int i=row,j=col;i<n &&j>=0 ;i++,j--)
     {
         if(board[i][j]=='Q')
         {
             return false;
         }
     }
     return true;
 }
 void solve(int col ,vector<vector<string>> &res,vector<string> & board,int n)
 {
        if(col == n)
        {
            res.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col] = 'Q';
                solve(col+1,res,board,n);
                board[i][col] = '.';
            }
        }
 }
    vector<vector<string>> solveNQueens(int n) {
        
           vector<string>board(n,string(n,'.'));
           vector<vector<string>>res;
           solve(0,res,board,n);
           return res;
    }
};