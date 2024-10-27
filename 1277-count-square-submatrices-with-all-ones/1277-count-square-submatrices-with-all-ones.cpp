class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> dp(col + 1, 0);  // Single-row DP array
        int ans = 0, prev = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int temp = dp[j + 1];
                if (matrix[i][j] == 1) {
                    dp[j + 1] = min({dp[j + 1], dp[j], prev}) + 1;
                    ans += dp[j + 1];
                } else {
                    dp[j + 1] = 0;
                }
                prev = temp;
            }
        }
        return ans;
    }
};

