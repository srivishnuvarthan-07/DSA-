#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list (u, v, wt)
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // since graph is undirected
        }

        // Step 2: Initialize distances
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // Step 3: Min-heap (priority queue) {dist, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        // Step 4: Dijkstra’s main loop
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (d > dist[node]) continue;

            // Relaxation step
            for (auto [nbr, wt] : adj[node]) {
                if (dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        return dist;
    }
};


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



int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}
    };
    int src = 0;

    vector<int> dist = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

