class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Pre-allocate memory to avoid multiple reallocations
        vector<pair<int, int>> intervalsWithEnd;
        intervalsWithEnd.reserve(intervals.size() * 2);

        // Convert the intervals to two events: start as {start, 1} and end as {end + 1, -1}
        for (const auto& interval : intervals) {
            intervalsWithEnd.emplace_back(interval[0], 1);  // Start of an interval
            intervalsWithEnd.emplace_back(interval[1] + 1, -1);  // End of an interval (exclusive)
        }

        // Sort the events by time (automatic pair sorting by first then second)
        sort(intervalsWithEnd.begin(), intervalsWithEnd.end());

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;

        // Traverse through the sorted events
        for (const auto& [time, delta] : intervalsWithEnd) {
            concurrentIntervals += delta;
            maxConcurrentIntervals = max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};
