class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int targetMod = totalSum % p;

        // If the total sum is already divisible by p, no subarray needs to be removed
        if (targetMod == 0) return 0;

        unordered_map<int, int> modIndexMap;  // To store mod of prefix sums and their indices
        modIndexMap[0] = -1;  // Handle the case where the entire prefix up to an index is valid
        long long prefixSum = 0;
        int minLen = n;  // Initialize minLen to the size of the array

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;  // Update prefix sum
            int currentMod = prefixSum % p;

            // Find if there's a prefix with a remainder (prefixSum - targetMod) % p
            int neededMod = (currentMod - targetMod + p) % p;

            // If we have seen a prefix with this mod, calculate the subarray length
            if (modIndexMap.count(neededMod)) {
                minLen = min(minLen, i - modIndexMap[neededMod]);
            }

            // Update the modIndexMap with the current prefix sum mod
            modIndexMap[currentMod] = i;
        }

        // If no valid subarray is found, return -1
        return minLen == n ? -1 : minLen;
    }
};
