class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k] =0;
        pq.push({0,k});

        vector<pair<int,int>> adj[n+1];
        for(auto it: times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        while(!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(dis + edgeWeight <dist[adjNode])
                {
                    dist[adjNode] = dis+ edgeWeight;
                    pq.push({dis+edgeWeight,adjNode});
                    
                }
            }
        }
        int res = -1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i] ==1e9)
            {
                return -1;
            }
            res = max(dist[i],res);
        } 
        return res;
    }
};