class Solution {
    bool dfscheck(int node,vector<vector<int>>& graph, vector<int>&vis, vector<int>&pathvis,vector<int> &check)
    {
         vis[node] =1;
         pathvis[node] =1;
          check[node] =0;
         for(auto it:graph[node])
         {
             if(!vis[it])
             {
                 if(dfscheck(it,graph,vis,pathvis,check)==true)
                 {
                    check[node] =0;
                    return true;
                 }
             }
             else if(pathvis[it]==1)
             {
                 check[node] =0;
                 return true;
             }

         }
         check[node] = 1;

         pathvis[node] =0;
         return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>vis(n,0),pathvis(n,0);
       vector<int>safeNodes;
       vector<int>check(n,0);
       
      for(int i=0;i<n;i++)
      {
          if(!vis[i])
          {
              dfscheck(i,graph,vis,pathvis,check);
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