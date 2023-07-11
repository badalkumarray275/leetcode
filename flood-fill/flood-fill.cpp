class Solution {
    void dfs(int sr,int sc,vector<vector<int>>& res,int color,int drow[],int dcol[],int inicol)
    {
           res[sr][sc] = color;
           int n = res.size();
           int m  = res[0].size();
           for(int i=0;i<4;i++)
           {
               int nrow = sr + drow[i];
               int ncol = sc + dcol[i];
               if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && 
               res[nrow][ncol] != color && res[nrow][ncol] == inicol)
                
                 dfs(nrow,ncol,res,color,drow,dcol,inicol);
           }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> res = image;
        int inicol = image[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(sr,sc,res,color,drow,dcol,inicol);
        return res;
    }
};