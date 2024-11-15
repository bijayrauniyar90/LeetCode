class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int right = n - 1;

        // Find the first decreasing element from the right
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        // If the entire array is already non-decreasing
        if (right == 0) {
            return 0;
        }

        int ans = right; // Initially, consider removing all elements to the left of `right`
        int left = 0;

        // Iterate from the left to find the optimal subarray to remove
        while (left < n && (left == 0 || arr[left - 1] <= arr[left])) {
            // Adjust `right` to maintain a non-decreasing subarray
            while (right < n && arr[left] > arr[right]) {
                right++;
            }
            // Update the minimum length of the subarray to remove
            ans = min(ans, right - left - 1);

            // Move the left pointer
            left++;
        }

        return ans;
    }
};
