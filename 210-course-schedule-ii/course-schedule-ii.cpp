class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<int> adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            
        }

        queue<int>q;
       vector<int>ans;
	    vector<int>indegree(numCourses,0);
	    for(int i=0;i<numCourses;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<numCourses;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
            ans.push_back(node);
	        q.pop();
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	            
	        }
	    }
       if(ans.size() ==numCourses ) return ans;
       return {};
    }
};