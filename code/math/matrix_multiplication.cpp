// Multiply two matrices A and B, and return the result in matrix C.
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

vector<vector<long long>> matrixMultiplication(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}