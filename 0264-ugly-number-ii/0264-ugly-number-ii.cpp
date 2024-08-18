class Solution {
public:
    int nthUglyNumber(int n) {
            priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
            unordered_set<long> seen;
        
        minHeap.push(1);  // Start with 1, the first ugly number
        seen.insert(1);   // Track the numbers already inserted into the heap

        long currentUgly = 1;
            vector<int> factors = {2, 3, 5};  // Ugly number factors

        for (int i = 0; i < n; i++) {
            currentUgly = minHeap.top();  // Get the smallest number from the heap
            minHeap.pop();                // Remove it from the heap

            // Insert the next potential ugly numbers
            for (int factor : factors) {
                long newUgly = currentUgly * factor;
                if (seen.find(newUgly) == seen.end()) {  // Only insert if it's not already in the heap
                    minHeap.push(newUgly);
                    seen.insert(newUgly);
                }
            }
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};