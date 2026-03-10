// Converts a binary string to its decimal representation

int binaryToDecimal(const string& binary) {
    int decimal = 0;
    for (size_t i = 0; i < binary.length(); i++) {
        if (binary[binary.length() - 1 - i] == '1') {
            decimal += (1 << i); // Add 2^i for each '1' found
        }
    }
    return decimal;
}