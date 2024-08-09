class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        // Traverse the grid, but only where a 3x3 square can fit
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                // Check if the center is 5 (since it's a necessary condition for a 3x3 magic square)
                if (grid[row + 1][col + 1] == 5 && isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // Check if all numbers are distinct and between 1 and 9
        bool seen[10] = {false};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || seen[num]) return false;
                seen[num] = true;
            }
        }

        // Compute the sums for the first row, column, and diagonals
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check all rows
        for (int i = 0; i < 3; i++) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum) {
                return false;
            }
        }

        // Check all columns
        for (int j = 0; j < 3; j++) {
            if (grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j] != sum) {
                return false;
            }
        }

        // Check diagonals
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum ||
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2] != sum) {
            return false;
        }

        return true;
    }
};
