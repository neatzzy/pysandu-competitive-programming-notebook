// Solve a system of linear equations using Cramer's rule
// Time complexity: O(n^4) in the worst case

// Function to calculate the determinant of a matrix
double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }
    double det = 0.0;
    for (int col = 0; col < n; col++) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j < col) {      
                    submatrix[i - 1][j] = matrix[i][j];
                } else if (j > col) {
                    submatrix[i - 1][j - 1] = matrix[i][j];
                }
            }
        }
        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(submatrix);
    }
    return det;
}

// Function to solve a system of linear equations using Cramer's rule
vector<double> solveLinearSystem(const vector<vector<double>>& A, const vector<double>& b) // A is the coefficient matrix and b is the constant vector
{
    int n = A.size();

    double detA = determinant(A);

    vector<double> solution(n);
    for (int i = 0; i < n; i++) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < n; ++j) {
            Ai[j][i] = b[j];
        }
        solution[i] = determinant(Ai) / detA; // Cramer's rule
    }
    return solution;
}