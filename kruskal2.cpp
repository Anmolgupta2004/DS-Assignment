#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Find with path compression
int findParent(int node, vector<int> &parent)
{
    if (parent[node] != node)
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

// Union by rank
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v)
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: \n";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter each edge in the format: u v weight (1-indexed):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    vector<int> parent(V + 1);
    vector<int> rank(V, 0);

    for (int i = 1; i <= V; ++i)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    for (Edge e : edges)
    {
        if (findParent(e.u, parent) != findParent(e.v, parent))
        {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSets(e.u, e.v, parent, rank);
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (Edge e : mst)
    {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";

    return 0;
}
