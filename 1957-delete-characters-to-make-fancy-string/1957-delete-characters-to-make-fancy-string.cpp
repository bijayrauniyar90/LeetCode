class Solution {
public:
    string makeFancyString(string s) {
        // If the length of the string is less than 3, return it directly
        if (s.size() < 3) return s;

        int writeIndex = 2;  // Index where the next valid character will be placed
        for (int i = 2; i < s.size(); ++i) {
            // Check if the current character forms a sequence of three with the last two characters
            if (s[i] != s[writeIndex - 1] || s[i] != s[writeIndex - 2]) {
                s[writeIndex++] = s[i];
            }
        }

        // Resize the string to the new valid length
        s.resize(writeIndex);
        return s;
    }
};
