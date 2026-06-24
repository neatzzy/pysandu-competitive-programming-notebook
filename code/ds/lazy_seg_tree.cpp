// Segment Tree com Lazy Propagation
// Complexidade: O(log N) para atualizações em range e consultas
struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}

    void push(int node, int tl, int tr) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (tr - tl + 1); // Exemplo para Soma
            if (tl != tr) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int tl, int tr, int l, int r, long long addend) {
        push(node, tl, tr);
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            lazy[node] += addend;
            push(node, tl, tr);
            return;
        }
        int tm = tl + (tr - tl) / 2;
        update(node * 2, tl, tm, l, r, addend);
        update(node * 2 + 1, tm + 1, tr, l, r, addend);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int tl, int tr, int l, int r) {
        push(node, tl, tr);
        if (l > tr || r < tl) return 0; // Elemento neutro
        if (l <= tl && tr <= r) return tree[node];
        int tm = tl + (tr - tl) / 2;
        return query(node * 2, tl, tm, l, r) + 
               query(node * 2 + 1, tm + 1, tr, l, r);
    }
};