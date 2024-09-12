class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentCount = 0;
        // Create a boolean array to store allowed characters
        vector<bool> isAllowed(26, false);
        
        // Mark allowed characters in the boolean array
        for (char c : allowed) {
            isAllowed[c - 'a'] = true;
        }

        // Iterate through each word in the words array
        for (const string& word : words) {
            bool isWordConsistent = true;

            // Check each character in the current word
            for (char c : word) {
                if (!isAllowed[c - 'a']) {
                    isWordConsistent = false;
                    break;  // No need to check remaining characters
                }
            }

            // If the word is consistent, increment the count
            if (isWordConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
