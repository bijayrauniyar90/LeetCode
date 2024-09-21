class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            dfs(start, n, result);
        }
        return result;
    }

private:
    void dfs(int current, int limit, vector<int>& result) {
        if (current > limit) return;  // Base condition

        result.push_back(current);  // Add the current number to the result

        // Explore next numbers by appending digits 0 to 9
        for (int next = 0; next <= 9; ++next) {
            int nextNumber = current * 10 + next;
            if (nextNumber > limit) break;  // No need to recurse if exceeds limit
            dfs(nextNumber, limit, result);  // Recursion with the new number
        }
    }
};
