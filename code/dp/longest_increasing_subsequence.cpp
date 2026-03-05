// Find the length of the longest increasing subsequence in a given array
// Time complexity: O(n log n) where n is the length of the input array

int lis(vector<int>& arr) {
    vector<int> dp; // dp[i] will hold the smallest tail of all increasing subsequences with length i+1
    for (int num : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), num); // Find the insertion point for num in dp
        if (it == dp.end()) {
            dp.push_back(num); // If num is larger than all elements in dp, add it to the end
        } else {
            *it = num; // Otherwise, replace the existing element with num
        }
    }
    return dp.size(); // The length of dp is the length of the longest increasing subsequence
}