// Find strongly connected components in a directed graph
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void kosarajuSharir(const Graph& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    stack<int> finishStack;

    // Step 1: Perform DFS and fill finishStack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, finishStack);
        }
    }

    // Step 2: Reverse the graph
    Graph reversedGraph = reverseGraph(graph);

    // Step 3: Perform DFS on reversed graph using finishStack order
    fill(visited.begin(), visited.end(), false);
    while (!finishStack.empty()) {
        int vertex = finishStack.top();
        finishStack.pop();

        if (!visited[vertex]) {
            vector<int> component;
            dfs(reversedGraph, vertex, visited, component);
            // component now contains all vertices in the strongly connected component
            cout << "Strongly Connected Component: ";
            for (int v : component) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}