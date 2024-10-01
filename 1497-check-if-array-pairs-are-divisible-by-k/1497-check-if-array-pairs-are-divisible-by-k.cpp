class Solution {
public:
    // Helper function to handle the non-negative remainder calculation.
    int positiveMod(int num, int k) {
        return (num % k + k) % k;
    }

    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Store the count of remainders in the map.
        for (int num : arr) {
            int rem = positiveMod(num, k);
            remainderCount[rem]++;
        }

        // Check if the pairs can be formed.
        for (int num : arr) {
            int rem = positiveMod(num, k);

            // Case 1: If remainder is 0, the count must be even to form pairs.
            if (rem == 0) {
                if (remainderCount[rem] % 2 != 0) {
                    return false;
                }
            }
            // Case 2: For other remainders, count of `rem` must equal count of `k - rem`.
            else if (remainderCount[rem] != remainderCount[k - rem]) {
                return false;
            }
        }

        return true;
    }
};
