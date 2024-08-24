class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = len % 2 == 0 ? len / 2 - 1 : len / 2;
        long firstHalf = stol(n.substr(0, i + 1));

        // Calculate the original number as a long
        long originalNumber = stol(n);
        
        // Possible candidates
        vector<long> possibilities = {
            createPalindrome(firstHalf, len % 2 == 0),
            createPalindrome(firstHalf + 1, len % 2 == 0),
            createPalindrome(firstHalf - 1, len % 2 == 0),
            (long)pow(10, len - 1) - 1,  // 999...9 (smallest n-digit palindrome)
            (long)pow(10, len) + 1       // 100...001 (smallest n+1-digit palindrome)
        };

        // Find the closest palindrome
        long closestPalindrome = 0;
        long minDifference = LONG_MAX;

        for (long candidate : possibilities) {
            if (candidate == originalNumber) continue;
            long currentDifference = abs(candidate - originalNumber);
            if (currentDifference < minDifference || (currentDifference == minDifference && candidate < closestPalindrome)) {
                minDifference = currentDifference;
                closestPalindrome = candidate;
            }
        }

        return to_string(closestPalindrome);
    }

private:
    long createPalindrome(long half, bool even) {
        long result = half;
        if (!even) half /= 10;
        while (half > 0) {
            result = result * 10 + half % 10;
            half /= 10;
        }
        return result;
    }
};