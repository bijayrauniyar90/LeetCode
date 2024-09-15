class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        // Store the XOR masks for vowels 'a', 'e', 'i', 'o', 'u'
        int characterMap[26] = {0};
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;

        // Initialize mp to store the earliest index with each prefixXOR value
        vector<int> mp(32, -1);  // 32 possible states for XOR (since 5 vowels => 2^5 = 32)
        mp[0] = 0;  // Initialize for the case where the entire substring from the start is valid

        int longestSubstring = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // If the current character is a vowel, update the prefix XOR
            if (characterMap[s[i] - 'a'] != 0) {
                prefixXOR ^= characterMap[s[i] - 'a'];
            }

            // If prefixXOR has been seen before, calculate the possible longest substring
            if (mp[prefixXOR] != -1) {
                longestSubstring = max(longestSubstring, i + 1 - mp[prefixXOR]);
            } else {
                // Store the first occurrence of this prefixXOR value
                mp[prefixXOR] = i + 1;
            }
        }

        return longestSubstring;
    }
};
