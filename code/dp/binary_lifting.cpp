// Binary lifting to find lower common ancestor in a binary tree
// Time complexity: O(log N) for queries and O(N log N) for pre-processing
// Memory complexity: O(N)
struct BinaryLifing{
    int n, l, timer; // n = size, l = max jump
    vector<int> tin, tout;
    vector<vector<int>> up;

    //Constructor
    BinaryLifing(int n, int root, const vector<vector<int>>& adj) : n(n), timer(0) {
        l = n <= 1 ? 0 : __lg(n) + 1;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(l+1));
        
        dfs(root, root, adj);
    }

    void dfs(int v, int p, const vector<vector<int>>& adj){
        tin[v] = ++timer;
        up[v][0] = p;

        for(int i = 1 ; i <= l ; i++) up[v][i] = up[up[v][i-1]][i-1];

        for(auto& u : adj[v]) if(u != p) dfs(u, v, adj);
        tout[v] = ++timer;
    }

    bool isAncestor(int u, int v){ return tin[u] <= tin[v] and tout[u] >= tout[v]; }

    int lca(int u, int v){
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;

        for(int i = l ; i >= 0 ; i--){
            if(!isAncestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }
};