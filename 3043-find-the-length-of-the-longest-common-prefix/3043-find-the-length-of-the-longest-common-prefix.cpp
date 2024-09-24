class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;  // Set to store all prefixes from arr1

        // Step 1: Build all possible prefixes from arr1 and insert into the set
        for (int val : arr1) {
            while (val > 0) {
                arr1Prefixes.insert(val);
                val /= 10;  // Remove the last digit to generate the next prefix
            }
        }

        int longestPrefix = 0;

        // Step 2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (val > 0) {
                if (arr1Prefixes.count(val)) {
                    // Calculate the length of the matched prefix without using log
                    int prefixLength = 0, temp = val;
                    while (temp > 0) {
                        temp /= 10;
                        prefixLength++;
                    }
                    longestPrefix = max(longestPrefix, prefixLength);
                    break;  // Stop once the longest prefix for this number is found
                }
                val /= 10;  // Remove the last digit if not found
            }
        }

        return longestPrefix;
    }
};
