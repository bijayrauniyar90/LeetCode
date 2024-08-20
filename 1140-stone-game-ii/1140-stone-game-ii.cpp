class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        unordered_map<int, unordered_map<int, int>> memo;
        return maxStones(suffixSum, 1, 0, memo);
    }

private:
    int maxStones(vector<int>& suffixSum, int maxTillNow, int currIndex,
                  unordered_map<int, unordered_map<int, int>>& memo) {
        int n = suffixSum.size();

        if (currIndex >= n) return 0;
        if (currIndex + 2 * maxTillNow >= n) return suffixSum[currIndex];
        
        if (memo[currIndex].count(maxTillNow)) return memo[currIndex][maxTillNow];
        
        int minOpponentStones = INT_MAX;

        for (int i = 1; i <= 2 * maxTillNow; ++i) {
            minOpponentStones = min(minOpponentStones, maxStones(suffixSum, max(i, maxTillNow),
                                                                 currIndex + i, memo));
        }

        memo[currIndex][maxTillNow] = suffixSum[currIndex] - minOpponentStones;
        return memo[currIndex][maxTillNow];
    }
};