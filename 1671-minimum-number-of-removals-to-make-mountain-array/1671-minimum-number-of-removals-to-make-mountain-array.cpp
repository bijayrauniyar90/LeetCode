class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lisLength(N, 1), ldsLength(N, 1);
        
        // Calculate LIS from left to right using binary search
        vector<int> lis;
        for (int i = 0; i < N; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (it == lis.end()) {
                lis.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            lisLength[i] = lis.size();
        }

        // Calculate LDS from right to left using binary search
        vector<int> lds;
        for (int i = N - 1; i >= 0; i--) {
            auto it = lower_bound(lds.begin(), lds.end(), nums[i]);
            if (it == lds.end()) {
                lds.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            ldsLength[i] = lds.size();
        }

        int minRemovals = INT_MAX;
        for (int i = 1; i < N - 1; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals = min(minRemovals, N - (lisLength[i] + ldsLength[i] - 1));
            }
        }

        return minRemovals;
    }
};
