class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, currentSum = 0;
        int begin = 0;

        unordered_map<int, int> count; // Tracks frequency of elements in the window

        for (int end = 0; end < nums.size(); ++end) {
            int currNum = nums[end];
            currentSum += currNum;
            count[currNum]++;

            // Shrink the window if it's invalid (duplicates or size > k)
            while (count[currNum] > 1 || end - begin + 1 > k) {
                currentSum -= nums[begin];
                count[nums[begin]]--;
                if (count[nums[begin]] == 0) {
                    count.erase(nums[begin]);
                }
                begin++;
            }

            // Update result if the window size is exactly k
            if (end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
        }

        return ans;
    }
};
