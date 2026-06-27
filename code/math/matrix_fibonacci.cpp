// Calculate the Nth Fibonacci number using matrix exponentiation.
// Time Complexity: O(log N)
// Space Complexity: O(1)

void matrixExponentiation(vector<vector<long long>>& matrix, long long power) {
    int n = matrix.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));

    // Initialize result as the identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    while (power) {
        if (power % 2 == 1) {
            result = matrixMultiplication(result, matrix);
        }
        matrix = matrixMultiplication(matrix, matrix);
        power /= 2;
    }

    matrix = result;
}