#include <bits/stdc++.h>
using namespace std;

void dfs(int &node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
        if(vis[node]==-1){
            vis[node]=1;
            for(int i:adj[node]){
                dfs(i,vis,adj,st);
            }
            st.push(node);
        }
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int>vis(V,-1);
    vector<vector<int>>adj(V);
    
    for(auto a:edges){
        adj[a[0]].push_back(a[1]);
    }
    
    vector<int>ino(V,0);
    for(auto a:edges){
        ino[a[1]]++;
    }
    
    queue<int>q;
    for(int i=0;i<V;i++){
        if(ino[i]==0){
            q.push(i);
        }
    }
    
    vector<int>topo;
    while(!q.empty()){
        int o=q.front();
        q.pop();
        topo.push_back(o);
        for(int i:adj[o]){
            ino[i]--;
            if(ino[i]==0){
                q.push(i);
            }
        }
    }
    return topo;
}

int main() {
	
	int V=4,E=3;
	vector<vector<int>>edges={{3,0},{1,0},{2,0}};
	vector<int>topo=topoSort(V,edges);
	for(int i:topo){
	    cout<<i<<" ";
	}
	cout<<endl;

}
