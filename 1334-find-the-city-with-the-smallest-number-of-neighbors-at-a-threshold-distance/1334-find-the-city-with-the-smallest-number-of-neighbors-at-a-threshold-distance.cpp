class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the shortest path matrix with infinity
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Set the diagonal to zero (distance to itself is zero)
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Populate the shortest path matrix with given edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w; // For undirected graph
        }

        // Floyd-Warshall algorithm to find shortest paths between all pairs
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }

        return cityWithFewestReachable;
    }
};