// Precompute factorials and inverse factorials modulo a prime MOD using DP
// Requires: powMod (modular_exponentiation.cpp)
// MOD must be prime (uses Fermat's little theorem: a^{-1} = a^{MOD-2} mod MOD)
// Time complexity: O(N) for precomputation, O(1) per query
// Space complexity: O(N)

const int MAXN = 1e6 + 5;
const long long MOD = 1e9 + 7;

long long fact[MAXN], inv_fact[MAXN];

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[n] = powMod(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// C(n, k) = n! / (k! * (n-k)!) mod MOD
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
