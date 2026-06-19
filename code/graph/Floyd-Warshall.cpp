// Find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    int INF = 1e8;

    for (int k = 0; k < V; k++) {

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(dist[i][k] != INF && dist[k][j]!= INF )
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
            }
        }
    }
}

