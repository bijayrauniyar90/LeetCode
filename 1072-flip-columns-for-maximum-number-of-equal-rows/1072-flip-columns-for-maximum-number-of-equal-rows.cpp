class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternFrequency;

        for (const auto& row : matrix) {
            string pattern;

            // Create a normalized pattern for the row
            for (int col = 0; col < row.size(); col++) {
                // Match first element ('T' if same, 'F' if flipped)
                pattern += (row[col] == row[0]) ? 'T' : 'F';
            }

            // Increment the frequency of the pattern
            patternFrequency[pattern]++;
        }

        // Find the pattern with the maximum frequency
        int maxFrequency = 0;
        for (const auto& [pattern, frequency] : patternFrequency) {
            maxFrequency = max(maxFrequency, frequency);
        }

        return maxFrequency;
    }
};
