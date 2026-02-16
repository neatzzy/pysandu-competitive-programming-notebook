// Find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

void floydWarshall(Graph& graph, vector<vector<int>>& dist) {
    int V = graph.size();
    
    for(int i = 0; i < V; i++){
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (dist[i][j] == 0) {
                dist[i][j] = INT_MAX; // No edge
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

