class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.size()) {
            return {}; // Return an empty 2D array
        }

        // Initialize the result 2D array with m rows and n columns
        vector<vector<int>> resultArray(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Use the formula to directly access the element in the original array
                resultArray[i][j] = original[i * n + j];
            }
        }

        return resultArray;
    }
};
