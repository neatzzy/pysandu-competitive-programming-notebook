// Find the position of the first element that is greater than the target value within a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int upperBound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}