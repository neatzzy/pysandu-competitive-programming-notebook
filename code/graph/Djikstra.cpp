// Find shortest path from a source vertex to all other vertices in a graph with non-negative edge weights
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V)

void dijkstra(const Graph& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& adj : graph[u]) {
            int v = adj.first;
            int weight = adj.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}