class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) return result;

        int start = 1, end = k, sum = 0;

        if (k < 0) {
            k = -k; // Convert k to positive for simpler logic
            start = n - k;
            end = n - 1;
        }

        // Compute the initial window sum
        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }

        // Use a sliding window approach
        for (int i = 0; i < n; i++) {
            result[i] = sum;

            // Update the sliding window
            sum -= code[start % n];
            sum += code[(end + 1) % n];

            start++;
            end++;
        }

        return result;
    }
};
