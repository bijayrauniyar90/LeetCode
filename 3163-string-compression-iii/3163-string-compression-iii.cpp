class Solution {
public:
    string compressedString(const string& word) {
        string comp;
        int pos = 0;
        int n = word.length();

        while (pos < n) {
            char currentChar = word[pos];
            int consecutiveCount = 1;
            pos++;

            // Count up to 9 consecutive occurrences of currentChar
            while (pos < n && word[pos] == currentChar && consecutiveCount < 9) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character
            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;
    }
};
