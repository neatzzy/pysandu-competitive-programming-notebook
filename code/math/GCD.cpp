// Calculates the Greatest Common Divisor (GCD) of two integers using Euclidean algorithm
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}