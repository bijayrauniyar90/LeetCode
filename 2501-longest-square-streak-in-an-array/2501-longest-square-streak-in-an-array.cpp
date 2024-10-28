class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Sort the array and use an unordered set for fast lookup
        sort(nums.begin(), nums.end());
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 0;

        for (int current : nums) {
            int streak = current;
            int streakLength = 1;

            // Continue the streak as long as we can find the square of the current number
            while ((long long)streak * streak <= 1e5 && numSet.count(streak * streak)) {
                streak *= streak;
                streakLength++;
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest streak
        return longestStreak < 2 ? -1 : longestStreak;
    }
};
