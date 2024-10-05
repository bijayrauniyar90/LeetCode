class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        // Frequency arrays for characters in s1 and sliding window in s2
        vector<int> countS1(26, 0), countWindow(26, 0);

        // Fill the frequency array for s1 and the first window of s2
        for (int i = 0; i < len1; i++) {
            countS1[s1[i] - 'a']++;
            countWindow[s2[i] - 'a']++;
        }

        // Check for the first window
        if (countS1 == countWindow) return true;

        // Start sliding the window over s2
        for (int i = len1; i < len2; i++) {
            // Add new character from the current window in s2
            countWindow[s2[i] - 'a']++;

            // Remove the character that goes out of the window
            countWindow[s2[i - len1] - 'a']--;

            // Check if current window matches s1's character frequencies
            if (countS1 == countWindow) return true;
        }

        return false;
    }
};
