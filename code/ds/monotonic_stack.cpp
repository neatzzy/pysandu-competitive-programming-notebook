// Increasing Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack to store indices

    for (int i = 0; i < 2 * n; ++i) {
        int num = arr[i % n]; // Circular array
        while (!st.empty() && arr[st.top()] < num) {
            res[st.top()] = num; // Update result for the index at the top of the stack
            st.pop(); // Pop the index from the stack
        }
        if (i < n) { // Only push indices from the first pass
            st.push(i);
        }
    }

    return res;
}

// Decreasing Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> nextSmallerElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack to store indices

    for (int i = 0; i < 2 * n; ++i) {
        int num = arr[i % n]; // Circular array
        while (!st.empty() && arr[st.top()] > num) {
            res[st.top()] = num; // Update result for the index at the top of the stack
            st.pop(); // Pop the index from the stack
        }
        if (i < n) { // Only push indices from the first pass
            st.push(i);
        }
    }

    return res;
}
