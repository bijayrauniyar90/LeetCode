#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int minVal = lower - nums[i];
            int maxVal = upper - nums[i];

            // Find the range of indices where the pair sum is within [lower, upper].
            auto low = std::lower_bound(nums.begin() + i + 1, nums.end(), minVal);
            auto high = std::upper_bound(nums.begin() + i + 1, nums.end(), maxVal);

            ans += std::distance(low, high);
        }

        return ans;
    }
};
