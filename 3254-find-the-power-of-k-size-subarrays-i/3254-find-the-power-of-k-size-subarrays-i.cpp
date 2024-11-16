class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1);

        if (k == 1) {
            // If k is 1, every element itself is the subarray
            for (int i = 0; i < length; i++) {
                result[i] = nums[i];
            }
            return result;
        }

        bool isConsecutiveAndSorted = true;

        // Initial check for the first window
        for (int i = 0; i < k - 1; i++) {
            if (nums[i + 1] != nums[i] + 1) {
                isConsecutiveAndSorted = false;
                break;
            }
        }

        result[0] = isConsecutiveAndSorted ? nums[k - 1] : -1;

        // Slide the window
        for (int start = 1; start <= length - k; start++) {
            if (isConsecutiveAndSorted) {
                // Check the new incoming element
                if (nums[start + k - 1] != nums[start + k - 2] + 1) {
                    isConsecutiveAndSorted = false;
                }
            } else {
                // Recheck the entire window
                isConsecutiveAndSorted = true;
                for (int i = start; i < start + k - 1; i++) {
                    if (nums[i + 1] != nums[i] + 1) {
                        isConsecutiveAndSorted = false;
                        break;
                    }
                }
            }

            result[start] = isConsecutiveAndSorted ? nums[start + k - 1] : -1;
        }

        return result;
    }
};
