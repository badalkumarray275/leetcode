class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,
        pair<int,int>>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        q.push({0,{0,0}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int diff = q.top().first;
            int row = q.top().second.first;
            int col =  q.top().second.second;
            q.pop();
            
            if(row == n-1 && col == m-1)
            {
                return diff;
            }
            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
               if(nrow<n && ncol <m && ncol>=0 && nrow>=0)
               {
                   int effort = max(abs(heights[row][col] -heights[nrow][ncol]),diff);
                   if(effort < dist[nrow][ncol])
                   {
                       dist[nrow][ncol] = effort;
                       q.push({effort,{nrow,ncol}});
                   }
               }

            }
        }
        return 0;
    }
};