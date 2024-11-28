class Solution {
private:
    // Directions for movement: right, left, down, up
    const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Priority queue to store cells as {obstacles, row, col}
        deque<tuple<int, int, int>> dq;

        // Vector to track the minimum obstacles to reach each cell
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        // Start from the top-left corner
        dq.push_front({0, 0, 0}); // {obstacles, row, col}
        minObstacles[0][0] = 0;

        while (!dq.empty()) {
            auto [obstacles, row, col] = dq.front();
            dq.pop_front();

            // If we've already found a better path, skip this cell
            if (obstacles > minObstacles[row][col]) continue;

            // Explore all four directions
            for (const auto& [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;

                // Check if the cell is within bounds
                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    int newObstacles = obstacles + grid[newRow][newCol];

                    // Update only if we find a path with fewer obstacles
                    if (newObstacles < minObstacles[newRow][newCol]) {
                        minObstacles[newRow][newCol] = newObstacles;
                        
                        // Use a deque to prioritize paths with fewer obstacles
                        if (grid[newRow][newCol] == 0) {
                            dq.push_front({newObstacles, newRow, newCol});
                        } else {
                            dq.push_back({newObstacles, newRow, newCol});
                        }
                    }
                }
            }
        }

        // Return the minimum obstacles to reach the bottom-right corner
        return minObstacles[m - 1][n - 1];
    }
};
