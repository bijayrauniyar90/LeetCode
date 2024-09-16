class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Handle edge case where we have more time points than possible minutes in a day
        if (timePoints.size() > 1440) {
            return 0; // Pigeonhole principle: at least two times must be identical
        }

        // Convert time strings to minutes since 00:00 and store in a vector
        vector<int> minutes;
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        // Sort the vector of minutes
        sort(minutes.begin(), minutes.end());

        // Initialize the minimum difference with the circular edge case
        int minDiff = 1440 + minutes[0] - minutes.back(); // considering circular time

        // Compute the minimum difference between consecutive times
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        return minDiff;
    }
};
