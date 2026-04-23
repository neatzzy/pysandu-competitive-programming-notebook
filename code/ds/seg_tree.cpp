// Segment Tree implementation
// Time complexity: O(log n) for updates and queries

template<typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    T combine(T a, T b) {
        // Combine function for the segment tree (e.g., sum, min, max)
        return a + b; // Example: sum
    }
    void build(vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, new_val);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return T(); // Return identity element (e.g., 0 for sum)
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
public:
    SegmentTree(vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    void update(int pos, T new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};