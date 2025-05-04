#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h> // for sleep()
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

// --------------------- Kruskal's ---------------------
struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void unite(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

void kruskal(int V, int E) {
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "\nBuilding MST using Kruskal's Algorithm...\n";
    int count = 0;
    for (Edge e : edges) {
        int ru = find(e.u, parent);
        int rv = find(e.v, parent);
        if (ru != rv) {
            cout << "Adding edge: " << e.u << " - " << e.v << " (Weight: " << e.w << ")\n";
            unite(ru, rv, parent);
            sleep(1);
            count++;
            if (count == V - 1) break;
        }
    }
    cout << "MST complete using Kruskal's.\n\n";
}

// --------------------- Prim's ---------------------
void prim(int V) {
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }

    vector<bool> selected(V, false);
    selected[0] = true;

    cout << "\nBuilding MST using Prim's Algorithm...\n";
    int edges = 0;
    while (edges < V - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << "Adding edge: " << x << " - " << y << " (Weight: " << graph[x][y] << ")\n";
        selected[y] = true;
        sleep(1);
        edges++;
    }
    cout << "MST complete using Prim's.\n\n";
}

// --------------------- Main Menu ---------------------
int main() {
    int choice, V, E;
    do {
        cout << "\n--- Minimum Spanning Tree Visualizer ---\n";
        cout << "1. Kruskal's Algorithm\n";
        cout << "2. Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of vertices and edges: ";
            cin >> V >> E;
            kruskal(V, E);
            break;

        case 2:
            cout << "Enter number of vertices: ";
            cin >> V;
            prim(V);
            break;

        case 3:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 3);

    return 0;
}



