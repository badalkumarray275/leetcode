class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long long,long long>> adj[n];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]}); 
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>q;
        vector<long long>dist(n,LONG_MAX),ways(n,0);
        dist[0] = 0;
        ways[0] =1;
        q.push({0,0});
        while(!q.empty())
        {
            long long dis = q.top().first;
            long long node = q.top().second;
            q.pop();
            
            for(auto it: adj[node])
            {
                long long adjNode = it.first;
                long long edgeWeight = it.second;
                  
                if(dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    ways[adjNode] = ways[node];
                    q.push({dis + edgeWeight,adjNode});
                }  
                else if(dis + edgeWeight == dist[adjNode])
                {
                    ways[adjNode]  =  (ways[adjNode] % 1000000007 + ways[node]%1000000007)%1000000007;
                }
            }
        }
        return ways[n-1] %1000000007;
    }
};