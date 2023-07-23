class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int> cost(n,1e9);
        cost[src]=0;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int  price = q.front().second.second;
            q.pop();
            if(stops > k)
            {
                continue;
            }
            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(price + edgeWeight < cost[adjNode] && stops <= k)
                {
                    cost[adjNode] = price + edgeWeight;
                    q.push({stops +1,{adjNode,price + edgeWeight}});
                }
            }
        }
        if(cost[dst]==1e9) return -1;
        return cost[dst];

    }
};