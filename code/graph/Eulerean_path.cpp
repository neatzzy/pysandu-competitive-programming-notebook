// Find the Eulerian path in a graph using Hierholzer's algorithm
// Time complexity: O(E) where E is the number of edges in the graph

void findEulerianPath(const vector<vector<int>>& graph, int start, vector<int>& path) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        if (graph[v].empty()) {
            path.push_back(v);
            s.pop();
        } else {
            int u = graph[v].back();
            graph[v].pop_back(); // Remove the edge from v to u
            s.push(u);
        }
    }
}