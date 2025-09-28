class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int>min_dist(n,1e9);
        min_dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int dist=it.second;
            for(int in:adj[node]){
                if(min_dist[in]>dist+1){
                    q.push({in,dist+1});
                    min_dist[in]=dist+1;
                }
                
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(min_dist[i]!=1e9){
                ans[i]=min_dist[i];
            }
        }
        return ans;
    }
};