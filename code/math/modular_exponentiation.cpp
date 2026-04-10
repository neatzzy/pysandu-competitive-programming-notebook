// Calculates (x^n) % MOD
// Time Complexity: O(log n)
// Space Complexity: O(1)

int powMod(int x, int n, int MOD){
    int res = 1;

    while(n > 0){
        if(n&1){
            res = (res * x) % MOD;
        }
        else{
            x = (x * x) % MOD;
        } n >>= 1;
    }
    return res;
}