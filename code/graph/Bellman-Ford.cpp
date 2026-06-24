// Find the shortest path from a source vertex to all other vertices in a graph with negative weight edges and detect negative weight cycles.
// Time Complexity: O(V * E)
// Space Complexity: O(V)

struct Edge { int u, v, weight; };

void bellmanFord(int V, const vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
}