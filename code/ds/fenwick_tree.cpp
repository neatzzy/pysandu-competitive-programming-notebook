// Fenwick Tree (1-based index)
// Time complexity: O(log N) for queries and updates

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) {
        s += T[i];
    }
    return s;
}

void add(int i, int k) {
    // i deve ser >= 1
    for (; i < T.size(); i += i & -i) {
        T[i] += k;
    }
}

// Construção em O(N)
void make() {
    for (int i = 1; i < T.size(); i++) {
        int p = i + (i & -i);
        if (p < T.size()) {
            T[p] += T[i];
        }
    }
}