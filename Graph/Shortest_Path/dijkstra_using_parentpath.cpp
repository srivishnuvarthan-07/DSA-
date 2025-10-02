#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns pair: {distances vector, parent vector}
    pair<vector<int>, vector<int>> dijkstra_with_parent(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            // undirected
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        const int INF = 1e9;
        vector<int> dist(V, INF);
        vector<int> parent(V, -1);

        dist[src] = 0;
        parent[src] = -1;

        // min-heap of (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // If this is an outdated entry, skip
            if (d > dist[u]) continue;

            for (auto &pr : adj[u]) {
                int v = pr.first;
                int w = pr.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        return {dist, parent};
    }

    // Utility to reconstruct path from src to dest using parent[]
    vector<int> get_path(int src, int dest, const vector<int> &parent) {
        vector<int> path;
        int cur = dest;
        while (cur != -1) {
            path.push_back(cur);
            if (cur == src) break;
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        // Optional: if path[0] != src then dest unreachable
        return path;
    }

    // Example function that returns the path from src to dest
    vector<int> shortest_path(int V, vector<vector<int>> &edges, int src, int dest) {
        auto [dist, parent] = dijkstra_with_parent(V, edges, src);
        if (dist[dest] == (int)1e9) {
            // unreachable
            return {}; // or return a sentinel, e.g. {-1}
        }
        return get_path(src, dest, parent);
    }
};