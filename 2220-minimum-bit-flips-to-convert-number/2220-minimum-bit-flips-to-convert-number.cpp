class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR start and goal to get the bits that differ
        int diff = start ^ goal;
        
        // Count the number of 1's in the binary representation of diff
        int count = 0;
        while (diff > 0) {
            count += diff & 1; // Check if the least significant bit is 1
            diff >>= 1;        // Shift to the next bit
        }
        
        return count;
    }
};
