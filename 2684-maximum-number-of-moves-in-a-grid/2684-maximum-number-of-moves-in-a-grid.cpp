class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        queue<pair<int, int>> q;  // Store row and column only.
        vector<vector<int>> vis(M, vector<int>(N, 0));

        // Initialize the queue with cells in the first column and mark as visited.
        for (int i = 0; i < M; i++) {
            q.push({i, 0});
            vis[i][0] = 1;
        }

        int maxMoves = 0;
        const int dirs[3] = {-1, 0, 1};  // Possible row movements for each column increment.

        while (!q.empty()) {
            int levelSize = q.size();
            bool moved = false;

            for (int i = 0; i < levelSize; ++i) {
                auto [row, col] = q.front();
                q.pop();

                for (int dir : dirs) {
                    int newRow = row + dir, newCol = col + 1;

                    if (newRow >= 0 && newRow < M && newCol < N && !vis[newRow][newCol] &&
                        grid[newRow][newCol] > grid[row][col]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                        moved = true;
                    }
                }
            }

            if (moved) maxMoves++;  // Only increase moves if a valid move was made.
        }

        return maxMoves;
    }
};
