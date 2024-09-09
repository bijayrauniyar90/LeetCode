class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Movement vectors: {right, down, left, up}
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int x = 0, y = 0, dir = 0;  // Start at top-left corner, direction: right
        
        while (head) {
            matrix[x][y] = head->val;  // Assign current value
            head = head->next;         // Move to next ListNode
            
            // Calculate next position
            int newX = x + directions[dir][0];
            int newY = y + directions[dir][1];
            
            // Check if the next position is out of bounds or already filled
            if (newX < 0 || newX >= m || newY < 0 || newY >= n || matrix[newX][newY] != -1) {
                dir = (dir + 1) % 4;  // Change direction
                newX = x + directions[dir][0];
                newY = y + directions[dir][1];
            }
            
            // Update position to next valid cell
            x = newX;
            y = newY;
        }
        
        return matrix;
    }
};
