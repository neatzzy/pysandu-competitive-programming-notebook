// Calculates (x^n) % MOD
// Time Complexity: O(log n)
// Space Complexity: O(1)

long long powMod(long long x, long long n, long long MOD){
    long long res = 1;
    x %= MOD;

    while(n >= 1){
        if(n & 1){
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}