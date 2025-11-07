#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;

vector<int> dijkstra(int V, vector<vector<pii>> &adj, int source) {
    vector<int> dist(V, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] > u_dist + weight) {
                dist[v] = u_dist + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V, E;
    cout << "=============================\n";
    cout << "  Dijkstra's Algorithm Demo\n";
    cout << "=============================\n\n";

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pii>> adj(V);

    cout << "\nEnter " << E << " edges (from to weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int source;
    cout << "\nEnter source vertex: ";
    cin >> source;

    cout << "\nCalculating shortest paths...\n\n";
    vector<int> distances = dijkstra(V, adj, source);

    cout << "----------------------------------------\n";
    cout << " Shortest Distances from Source Vertex " << source << "\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << setw(2) << i << " : ";
        if (distances[i] == INF)
            cout << "Unreachable\n";
        else
            cout << distances[i] << "\n";
    }
    cout << "----------------------------------------\n";

    return 0;
}
