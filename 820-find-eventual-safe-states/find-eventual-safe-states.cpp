class Solution {
    private:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis
      ,vector<int>& pathVis,vector<int>& check)
      {
          vis[node] = 1;
          pathVis[node] =1;
          check[node] =0;

          for(auto it: graph[node])
          {
              if(!vis[it])
              {
                   if(dfs(it,graph,vis,pathVis,check)==true)
                   {
                       return true;
                   }
              }
              else if(pathVis[it]==1)
              {
                  return true;
              }
          }

          check[node] =1;
          pathVis[node] =0;
          return false;
      }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int>vis(n,0),pathVis(n,0),check(n,0);
        vector<int> safeNodes;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};