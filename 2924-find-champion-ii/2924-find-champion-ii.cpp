class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        // Calculate indegree of each team.
        for (const auto& edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1;

        // Check for the team with indegree 0. If there's more than one, return -1.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (champ != -1) {
                    // More than one champion found.
                    return -1;
                }
                champ = i;
            }
        }

        return champ;
    }
};
