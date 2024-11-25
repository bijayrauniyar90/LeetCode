class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2D board into a string representation
        string startState;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                startState += to_string(board[i][j]);
            }
        }

        // Target state
        const string target = "123450";

        // If the initial state is the target, return 0 moves
        if (startState == target) return 0;

        // Direction map for zero's possible moves in a flattened 1D array
        vector<vector<int>> directions = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {3, 5, 1}, {4, 2}
        };

        // Queue for BFS: each entry contains the current state and the number of moves
        queue<pair<string, int>> q;
        q.push({startState, 0});

        // Set to track visited states
        unordered_set<string> visited;
        visited.insert(startState);

        while (!q.empty()) {
            auto [currentState, moves] = q.front();
            q.pop();

            // Find the position of '0'
            int zeroPos = currentState.find('0');

            // Explore all possible moves
            for (int nextPos : directions[zeroPos]) {
                string nextState = currentState;
                swap(nextState[zeroPos], nextState[nextPos]);

                // If the target state is reached, return the number of moves
                if (nextState == target) return moves + 1;

                // If the state is not visited, enqueue it
                if (!visited.count(nextState)) {
                    visited.insert(nextState);
                    q.push({nextState, moves + 1});
                }
            }
        }

        // If no solution is found, return -1
        return -1;
    }
};