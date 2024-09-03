class Solution {
public:
    int getLucky(string s, int k) {
        // Initial digit sum calculation from the character string
        int digitSum = 0;
        for (char ch : s) {
            int num = ch - 'a' + 1;
            digitSum += num / 10 + num % 10;  // Add the sum of the digits directly
        }

        // Apply the transformation k-1 times
        while (--k > 0) {
            int newSum = 0;
            while (digitSum > 0) {
                newSum += digitSum % 10;
                digitSum /= 10;
            }
            digitSum = newSum;
        }

        return digitSum;
    }
};
