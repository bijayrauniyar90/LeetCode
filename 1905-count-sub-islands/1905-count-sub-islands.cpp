class Solution {
    // Directions in which we can traverse inside the grids.
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, const vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    // Depth-First Search to mark all cells in the island and check if it's a sub-island.
    bool dfs(int x, int y, const vector<vector<int>>& grid1, const vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        // Base case: check boundaries and whether the cell is a land cell and not visited.
        if (x < 0 || x >= grid2.size() || y < 0 || y >= grid2[0].size() || visited[x][y] || grid2[x][y] == 0) {
            return true;
        }

        visited[x][y] = true;

        // Check if the current cell is part of grid1.
        bool isSubIsland = isCellLand(x, y, grid1);

        // Traverse all directions.
        for (const auto& direction : directions) {
            int nextX = x + direction.first;
            int nextY = y + direction.second;
            // Recursively check all adjacent cells.
            isSubIsland &= dfs(nextX, nextY, grid1, grid2, visited);
        }

        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int subIslandCounts = 0;

        // Iterate on each cell in 'grid2'
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                // If cell at the position (x, y) in 'grid2' is a land cell and not visited
                if (!visited[x][y] && isCellLand(x, y, grid2)) {
                    // If the island starting from this cell is a sub-island in 'grid1', increment the count.
                    if (dfs(x, y, grid1, grid2, visited)) {
                        ++subIslandCounts;
                    }
                }
            }
        }
        // Return total count of sub-islands.
        return subIslandCounts;
    }
};
