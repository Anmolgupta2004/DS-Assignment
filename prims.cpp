#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

int primMST(int V, vector<vector<pii>> &adj)
{

    vector<bool> inMST(V + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int totalWeight = 0;

    // Start from vertex 1
    pq.push({0, 1});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;
        totalWeight += weight;

        for (auto &edge : adj[u])
        {
            int w = edge.first;
            int v = edge.second;
            if (!inMST[v])
            {
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    vector<vector<pii>> adj(V + 1); // 1-indexed

    cout << "Enter each edge in format: u v weight: \n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // undirected graph
    }

    int mstWeight = primMST(V, adj);
    cout << "Total weight of MST: " << mstWeight << "\n";

    return 0;
}
