class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // Min-heap to store the current elements from each list
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int curMax = INT_MIN;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i});
            curMax = max(curMax, nums[i][0]);
        }

        // Store the smallest range
        vector<int> range = {minHeap.top().first, curMax};
        vector<int> indices(k, 0);  // Tracks the current index of each list

        while (true) {
            auto [curMin, listIndex] = minHeap.top();
            minHeap.pop();

            // Update the range if a smaller one is found
            if (curMax - curMin < range[1] - range[0]) {
                range = {curMin, curMax};
            }

            // Move to the next element in the list that had the minimum value
            if (++indices[listIndex] == nums[listIndex].size()) break;

            // Add the next element from the same list to the heap
            int nextElement = nums[listIndex][indices[listIndex]];
            minHeap.push({nextElement, listIndex});

            // Update the current maximum element
            curMax = max(curMax, nextElement);
        }

        return range;
    }
};