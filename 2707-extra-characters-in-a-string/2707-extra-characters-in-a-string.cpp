class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        vector<int> memo(n + 1, -1);  // Use vector instead of unordered_map

        function<int(int)> dp = [&](int start) -> int {
            if (start == n) {
                return 0;
            }
            if (memo[start] != -1) {
                return memo[start];
            }
            // To count this character as a leftover character 
            int ans = dp(start + 1) + 1;
            // Iterate over possible substrings without creating them
            for (int end = start; end < n; ++end) {
                if (dictionarySet.count(s.substr(start, end - start + 1))) {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
        };

        return dp(0);
    }
};
