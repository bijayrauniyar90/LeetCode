class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // 1-based to 0-based index adjustment

        while (k > 0) {
            int steps = countSteps(n, curr);
            if (steps <= k) {
                curr++;  // Move to the next sibling
                k -= steps;  // Skip all these numbers in this subtree
            } else {
                curr *= 10;  // Move down to the first child
                k--;  // Step into the next level
            }
        }

        return curr;
    }

private:
    int countSteps(int n, long long prefix) {
        long long prefix1 = prefix, prefix2 = prefix + 1;
        int steps = 0;

        while (prefix1 <= n) {
            steps += min(n + 1LL, prefix2) - prefix1;
            prefix1 *= 10;  // Move to the next level in the tree
            prefix2 *= 10;
        }

        return steps;
    }
};
