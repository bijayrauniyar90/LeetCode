class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> degree;

        // Build the adjacency list and track degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyList[start].push_back(end);
            degree[start]++;
            degree[end]--;
        }

        vector<int> result;

        // Helper function for Hierholzer's Algorithm (Eulerian Path)
        function<void(int)> dfs = [&](int node) {
            auto& edges = adjacencyList[node];
            while (!edges.empty()) {
                int nextNode = edges.back();
                edges.pop_back();
                dfs(nextNode);
            }
            result.push_back(node);
        };

        // Find start node for the Eulerian Path
        int startNode = pairs[0][0];
        for (const auto& [node, deg] : degree) {
            if (deg == 1) {
                startNode = node;
                break;
            }
        }

        // Start DFS
        dfs(startNode);

        // Construct result pairs in reverse order
        vector<vector<int>> pairedResult;
        for (int i = result.size() - 1; i > 0; --i) {
            pairedResult.push_back({result[i], result[i - 1]});
        }

        return pairedResult;
    }
};
