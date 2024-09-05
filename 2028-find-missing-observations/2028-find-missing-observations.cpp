class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalSum = mean * (n + rolls.size());  // Calculate total expected sum
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);  // Sum of given rolls
        
        int remainingSum = totalSum - currentSum;  // Remaining sum to distribute
        
        // Check if the remaining sum is within the valid range for `n` dice rolls.
        if (remainingSum < n || remainingSum > 6 * n) {
            return {};
        }
        
        // Distribute the remaining sum across the `n` elements.
        vector<int> result(n, remainingSum / n);  // Initialize with the mean value
        int extra = remainingSum % n;  // Distribute the extra part
        
        // Distribute the extra points across the first `extra` elements
        for (int i = 0; i < extra; i++) {
            result[i]++;
        }
        
        return result;
    }
};
