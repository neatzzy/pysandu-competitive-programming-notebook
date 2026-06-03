// SPF sieve implementation for finding the smallest prime factor of each number up to a given limit.
// Time complexity: O(n log log n) for the sieve construction, O(log n) for factorization of each number.

#define MAXN 1000000 // Maximum limit for the sieve
std::vector<int> spf(MAXN + 1);

void sieve() {
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
