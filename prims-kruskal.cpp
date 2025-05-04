#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>  // For sleep()

using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

// Find root of node u
int find(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

// Union two sets
void unite(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    vector<int> parent(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), compare);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "\nBuilding MST using Kruskal's Algorithm...\n";
    for (Edge e : edges) {
        int root_u = find(e.u, parent);
        int root_v = find(e.v, parent);
        if (root_u != root_v) {
            cout << "Adding edge: " << e.u << " - " << e.v << " (Weight: " << e.w << ")\n";
            unite(root_u, root_v, parent);
            sleep(1);  // 1-second pause
        }
    }

    cout << "MST complete.\n";
    return 0;
}


