class Solution {

private:
    int f(int i1,int j1,int i2,int n,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)    
    {
        int j2 = i1+ j1 - i2;
        if(i1<0 || j1<0 || i2 <0 || j2<0) return -1e9;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e9;
       if(i1==0 && j1==0) return grid[i1][j1];
          
          if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
       int maxi = 0;
       if(i1==i2 && j1 == j2) maxi += grid[i1][j1];
       else maxi += grid[i1][j1] + grid[i2][j2];
      
        int a = f(i1-1,j1,i2,n,grid,dp);
        int b = f(i1-1,j1,i2-1,n,grid,dp);
        int c = f(i1,j1-1,i2,n,grid,dp);
        int d = f(i1,j1-1,i2-1,n,grid,dp);
        
        maxi +=  max(max(a,b),max(c,d));
        return dp[i1][j1][i2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
       int ans = f(n-1,n-1,n-1,n,grid,dp);
       return ans>=0 ? ans :0;
    }
};