// Reverse the edges of a directed graph
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

Graph reverseGraph(const Graph& graph) {
    int V = graph.size();
    Graph reversedGraph(V);

    for (int u = 0; u < V; u++) {
        for (int v : graph[u]) {
            reversedGraph[v].push_back(u);
        }
    }

    return reversedGraph;
}