class Solution {
public:
    // Helper function to check if a given max quantity `x` can be achieved with `n` stores
    bool canDistribute(int maxQuantity, vector<int>& quantities, int stores) {
        int storeCount = 0;

        // Calculate required stores for each product type with max `maxQuantity` per store
        for (int quantity : quantities) {
            // Calculate how many stores are needed for the current product type
            storeCount += (quantity + maxQuantity - 1) / maxQuantity;
            // If the required store count exceeds available stores, return false
            if (storeCount > stores) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1; // Start from 1 because distributing 0 items isn't practical
        int right = *max_element(quantities.begin(), quantities.end());

        // Perform binary search to find the minimal maximum quantity
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (canDistribute(middle, quantities, n)) {
                right = middle; // Try for a smaller maximum
            } else {
                left = middle + 1; // Increase the minimum possible maximum
            }
        }
        return left;
    }
};
