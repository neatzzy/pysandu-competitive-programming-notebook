// Solve a system of linear equations using LU decomposition with partial pivoting
// Time complexity: O(n^3) for decomposition, O(n^2) for forward and backward substitution

void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, vector<int>& perm) {
    int n = A.size();
    U = A;
    L.assign(n, vector<double>(n, 0));
    perm.resize(n);
    iota(perm.begin(), perm.end(), 0);

    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
            if (abs(U[k][i]) > abs(U[maxRow][i])) maxRow = k;
        swap(U[i], U[maxRow]);
        swap(perm[i], perm[maxRow]);
        for (int k = 0; k < i; k++) swap(L[i][k], L[maxRow][k]);

        L[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            L[j][i] = U[j][i] / U[i][i];
            for (int k = i; k < n; k++)
                U[j][k] -= L[j][i] * U[i][k];
        }
    }
}

// perm is the permutation vector returned by luDecomposition
void forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b, const vector<int>& perm, vector<double>& y) {
    int n = L.size();
    for (int i = 0; i < n; i++) {
        y[i] = b[perm[i]];
        for (int j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
    }
}

void backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y, vector<double>& x) {
    int n = U.size();
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }
}
