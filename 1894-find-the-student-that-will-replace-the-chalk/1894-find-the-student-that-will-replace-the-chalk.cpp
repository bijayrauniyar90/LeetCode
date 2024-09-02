class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the sum of the chalk array.
        long long totalChalk = 0;
        for (int i = 0; i < chalk.size(); i++) {
            totalChalk += chalk[i];
        }
        
        // Reduce k by the sum to find the effective chalk usage.
        k %= totalChalk;
        
        // Determine which student will replace the chalk.
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // The loop should always return within the above loop.
        return 0;
    }
};
