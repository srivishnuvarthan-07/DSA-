// User function Template for C++
class Solution {
    
    public:
        void dfs(int node,vector<int>&vis,vector<vector<pair<int,int>>>&adj,stack<int>&st){
            if(vis[node]==-1){
                vis[node]=1;
                for(auto i:adj[node]){
                    int j=i.first;
                    dfs(j,vis,adj,st);
                }
                st.push(node);
            }
        }
        

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V,vector<pair<int,int>>());
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        
        stack<int>st;
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>dist(V,1e9);
        dist[0]=0;
        while(!st.empty()){
            int a=st.top();
            st.pop();
            for(auto i:adj[a]){
                dist[i.first]=min(dist[i.first],i.second+dist[a]);
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
        

    }
};
