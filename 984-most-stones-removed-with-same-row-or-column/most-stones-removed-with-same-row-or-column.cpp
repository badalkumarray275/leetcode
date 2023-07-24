class DisjointSet
{
  
    public:
    vector<int>parent,rank,size;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node]=   findUpar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u==ulp_v) return ;

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;

        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]= ulp_u;

        }
        else{
             parent[ulp_v]= ulp_u;
             rank[ulp_u]++;
        }

    }
    void unionBySize(int u,int v)
    {
         int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];

        }
        else
        {
             parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
              int maxRow = 0;
              int n = stones.size();
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUpar(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};