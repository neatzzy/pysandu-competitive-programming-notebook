// Find the length of the longest increasing subsequence in a given array
// Time complexity: O(n log n) where n is the length of the input array

int lis(vector<int>& arr) {
    vector<int> dp;
    for (int num : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return dp.size();
}