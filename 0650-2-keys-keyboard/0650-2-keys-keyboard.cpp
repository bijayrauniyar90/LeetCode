class Solution {
    int n;
        unordered_map<int, int> memo;

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;
        // first step is always a Copy All operation
        return 1 + minStepsHelper(1, 1);
    }

private:
    int minStepsHelper(int currLen, int pasteLen) {
        // base case: reached n A's, don't need more operations
        if (currLen == n) return 0;
        // base case: exceeded n A's, not a valid sequence
        if (currLen > n) return 1000;

        // create a unique key for memoization
        int key = currLen * 1000 + pasteLen;
        if (memo.find(key) != memo.end()) return memo[key];

        // copy all + paste
        int opt1 = 2 + minStepsHelper(currLen * 2, currLen);
        // paste
        int opt2 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);

        // store result in memo before returning
        memo[key] = std::min(opt1, opt2);
        return memo[key];
    }
};
