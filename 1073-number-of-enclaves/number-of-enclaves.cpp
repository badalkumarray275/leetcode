class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i== n-1 || j== 0 ||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        int count =0;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow<n && nrow>=0 && ncol >=0 && ncol <m
                && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};