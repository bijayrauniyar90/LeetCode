class Solution {
public:
    int countMaxOrSubsets(const vector<int>& nums) {
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;  // Calculate the maximum OR value
        }
        return countSubsets(nums, 0, 0, maxOrValue);
    }

private:
    int countSubsets(const vector<int>& nums, int index, int currentOr, int targetOr) {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Recursive case: explore both including and excluding the current element
        int countWithout = countSubsets(nums, index + 1, currentOr, targetOr);  // Exclude current element
        int countWith = countSubsets(nums, index + 1, currentOr | nums[index], targetOr);  // Include current element

        return countWithout + countWith;  // Sum the counts from both cases
    }
};
