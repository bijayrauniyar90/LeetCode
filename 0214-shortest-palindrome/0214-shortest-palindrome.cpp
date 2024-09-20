class Solution {
public:
    string shortestPalindrome(string s) {
        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());
        
        // Concatenate original string and reversed string with a delimiter
        string combined = s + "#" + reversedString;
        
        // Compute the prefix table (partial match table) for the combined string
        vector<int> prefix(combined.size(), 0);
        for (int i = 1; i < combined.size(); ++i) {
            int j = prefix[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = prefix[j - 1];
            }
            
            if (combined[i] == combined[j]) {
                ++j;
            }
            prefix[i] = j;
        }
        
        // The length of the longest palindromic prefix is given by the value of the last element in the prefix array
        int longestPalindromicPrefix = prefix.back();
        
        // Append the necessary characters from the reversed string to make the palindrome
        return reversedString.substr(0, s.size() - longestPalindromicPrefix) + s;
    }
};
