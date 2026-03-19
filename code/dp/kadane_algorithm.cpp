// Find maximum subarray sum using Kadane's algorithm
// Time complexity: O(n) where n is the length of the input array

int maxSubArraySum(const vector<int>& arr) {
    int maxSum = arr[0];
    int maxLocal = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        maxLocal = max(arr[i], maxLocal + arr[i]);
        maxSum = max(maxSum, maxLocal);
    }

    return maxSum;
}