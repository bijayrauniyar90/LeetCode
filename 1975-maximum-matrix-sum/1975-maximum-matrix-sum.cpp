class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (const auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);              // Sum absolute values directly
                negativeCount += (val < 0);        // Count negatives efficiently
                minAbsVal = min(minAbsVal, abs(val)); // Track smallest absolute value
            }
        }

        // If the total count of negative numbers is odd, adjust the sum
        if (negativeCount % 2) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};
