class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> previousRow(cols), leftMax(cols), rightMax(cols);

        // Initialize the first row
        for (int col = 0; col < cols; ++col) {
            previousRow[col] = points[0][col];
        }

        // Process each row
        for (int row = 1; row < rows; ++row) {
            // Calculate left-to-right maximum
            leftMax[0] = previousRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
            }

            // Calculate right-to-left maximum
            rightMax[cols - 1] = previousRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
            }

            // Update previousRow with the maximum values for the current row
            for (int col = 0; col < cols; ++col) {
                previousRow[col] = points[row][col] + max(leftMax[col], rightMax[col]);
            }
        }

        // Find the maximum value in the last processed row
        return *max_element(previousRow.begin(), previousRow.end());
    }
};
