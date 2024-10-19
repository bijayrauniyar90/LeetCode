class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to find the kth bit recursively
        return findKthBitHelper(n, k);
    }

    char findKthBitHelper(int n, int k) {
        // Base case: If n is 1, the sequence is "0"
        if (n == 1) {
            return '0';
        }

        // Calculate the length of Sn: 2^n - 1
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;

        // If k is the middle element, it's always '1'
        if (k == mid) {
            return '1';
        }
        // If k is in the first half, it's the same as S_(n-1)
        else if (k < mid) {
            return findKthBitHelper(n - 1, k);
        }
        // If k is in the second half, it's the reverse and inverted bit from S_(n-1)
        else {
            char bit = findKthBitHelper(n - 1, length - k + 1);
            return bit == '0' ? '1' : '0';
        }
    }
};
