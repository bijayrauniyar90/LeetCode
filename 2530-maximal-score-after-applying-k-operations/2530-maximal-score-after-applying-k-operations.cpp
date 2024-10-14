class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        // Create max-heap to store the elements.
        priority_queue<int> pq(nums.begin(), nums.end());

        while (k--) {
            // Add the max element to the answer and push its one-third value back into the heap.
            int maxElement = pq.top();
            ans += maxElement;
            pq.pop();
            // Push one-third of maxElement, rounding up.
            pq.push((maxElement + 2) / 3);
        }

        return ans;
    }
};