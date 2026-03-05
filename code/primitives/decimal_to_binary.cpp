// Convert a decimal number to its binary representation

string decimalToBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary; // Return "0" if n is 0
}