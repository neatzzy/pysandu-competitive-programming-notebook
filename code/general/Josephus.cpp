// Josephus problem
// Time complexity: O(N)
// Memory complexity: O(1)

// Recursive (1 indexing)
int memo[MAX_N];

int josephus(int n, int k) {
    if (n == 1) return 1;
    if (memo[n]) return memo[n];
    return memo[n] = (josephus(n-1, k) + k - 1) % n + 1;
}

// Non-Recursive
int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
}