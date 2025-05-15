#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void dijkstra(int V, vector<vector<pii>>& adj, int start) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[u]) continue; // Skip outdated pair

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To " << i << " : ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges in the format: u v weight (Number of vertex start from zero):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // If the graph is undirected, also add:
        // adj[v].push_back({u, w});
    }

    int start;
    cout << "Enter the source vertex: ";
    cin >> start;

    dijkstra(V, adj, start);

    return 0;
}
