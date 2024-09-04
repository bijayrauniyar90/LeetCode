class Solution {
private:
    static const int HASH_MULTIPLIER = 60001; // Slightly larger than 2 * max coordinate value

    // Hash function to convert (x, y) coordinates to a unique integer value
    int hashCoordinates(int x, int y) {
        return x + HASH_MULTIPLIER * y;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles in an unordered_set for efficient lookup
        unordered_set<int> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }

        // Define direction vectors: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x = 0, y = 0, maxDistanceSquared = 0;
        int currentDirection = 0;  // 0: North, 1: East, 2: South, 3: West

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                currentDirection = (currentDirection + 1) % 4;
            } else if (command == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
            } else {
                // Move forward
                for (int step = 0; step < command; ++step) {
                    int nextX = x + directions[currentDirection].first;
                    int nextY = y + directions[currentDirection].second;
                    if (obstacleSet.count(hashCoordinates(nextX, nextY))) {
                        break;  // Stop if there's an obstacle
                    }
                    x = nextX;
                    y = nextY;
                    maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                }
            }
        }

        return maxDistanceSquared;
    }
};
