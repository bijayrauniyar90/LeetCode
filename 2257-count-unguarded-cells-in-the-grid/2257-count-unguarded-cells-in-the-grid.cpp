class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markguarded(int row, int col, vector<vector<int>>& grid, int m, int n) {
        // Lambda to traverse in a specific direction
        auto traverse = [&](int dr, int dc) {
            int r = row + dr, c = col + dc;
            while (r >= 0 && r < m && c >= 0 && c < n) {
                if (grid[r][c] == WALL || grid[r][c] == GUARD) break;
                if (grid[r][c] == UNGUARDED) grid[r][c] = GUARDED;
                r += dr;
                c += dc;
            }
        };

        // Traverse in four directions
        traverse(-1, 0); // Up
        traverse(1, 0);  // Down
        traverse(0, -1); // Left
        traverse(0, 1);  // Right
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards and walls
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark guarded cells
        for (const auto& guard : guards) {
            markguarded(guard[0], guard[1], grid, m, n);
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) unguardedCount++;
            }
        }
        return unguardedCount;
    }
};
