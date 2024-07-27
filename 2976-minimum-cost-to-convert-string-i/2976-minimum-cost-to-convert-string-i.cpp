class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        long long totalCost = 0;
        int n = source.size();
        
        vector<vector<long long>> minCost(26, vector<long long>(26, LLONG_MAX));
        
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int startChar = original[i] - 'a';
            int endChar = changed[i] - 'a';
            minCost[startChar][endChar] = min(minCost[startChar][endChar], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] < LLONG_MAX && minCost[k][j] < LLONG_MAX) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                int sourceChar = source[i] - 'a';
                int targetChar = target[i] - 'a';
                if (minCost[sourceChar][targetChar] == LLONG_MAX) {
                    return -1;
                }
                totalCost += minCost[sourceChar][targetChar];
            }
        }

        return totalCost;
    }
};