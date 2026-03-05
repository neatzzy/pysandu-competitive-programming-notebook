// Prim's algorithm for finding the Minimum Spanning Tree
// Time complexity: O(E log V) where E is the number of edges and V is the number of vertices

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight; // Min-heap
    }
};

vector<Edge> primMST(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<Edge> mst;
    priority_queue<Edge> pq;

    // Start with the first vertex
    visited[0] = true;
    for (int i = 0; i < n; ++i) {
        if (graph[0][i] != 0) {
            pq.push({0, i, graph[0][i]});
        }
    }

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        if (visited[current.v]) continue;

        visited[current.v] = true;
        mst.push_back(current);

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && graph[current.v][i] != 0) {
                pq.push({current.v, i, graph[current.v][i]});
            }
        }
    }

    return mst;
}