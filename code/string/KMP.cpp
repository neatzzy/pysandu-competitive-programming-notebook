// Find all occurrences of a pattern in a given text using the Knuth-Morris-Pratt (KMP) algorithm
// Time complexity: O(n + m) where n is the length of the text and m is the length of the pattern

vector<int> LPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(const string& text, const string& pattern) {
    vector<int> lps = LPS(pattern);
    vector<int> occurrences;
    int n = text.size();
    int m = pattern.size();
    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - j); // Pattern found at index (i - j)
            j = lps[j - 1]; // Continue to search for the next match
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occurrences;
}