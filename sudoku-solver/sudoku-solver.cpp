class Solution {
public:
 bool isSafe(int i,int j,vector<vector<char>>& board ,char num,int n)
 {
     for(int k=0;k<n;k++)
     {
         if(board[i][k]==num || board[k][j]==num)
           return false;
     }
     
     int s = sqrt(n);
     int rs = i-i%s;
     int cs = j-j%s;
     for(int i=0;i<s;i++)
     {
         for(int j=0;j<s;j++)
         {
             if(board[i+rs][j+cs]==num)
             {
                 return false;
             }
         }
     }
     return true;
 }
 bool solve(vector<vector<char>>& board,int n)
 {
     int i,j;
     for( i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            if(board[i][j]=='.')
            {
                  for(char num = '1';num<='9';num++)
                 {
                     if(isSafe(i,j,board,num,n))
                    {
                        board[i][j] = num;
                        if(solve(board,n))
                        {
                           return true;
                        }
                         board[i][j] = '.';
                      } 
                 }
                 return false;
            }
         }
     }
      return true;
 }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
          solve(board ,n);
    }
};