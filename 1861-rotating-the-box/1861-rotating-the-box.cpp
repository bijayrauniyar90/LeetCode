class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        // Create the result grid with rotated dimensions
        vector<vector<char>> result(n, vector<char>(m, '.'));
        
        // Process the rotation and gravity in a single pass
        for (int i = 0; i < m; i++) {
            int writePtr = n - 1; // Pointer to place the next stone
            
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    // Place the stone in the lowest available position
                    result[writePtr--][m - 1 - i] = '#';
                } else if (box[i][j] == '*') {
                    // Obstacle; reset the write pointer
                    result[j][m - 1 - i] = '*';
                    writePtr = j - 1;
                }
            }
        }
        
        return result;
    }
};
