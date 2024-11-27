class Solution {
public:
    // Optimized BFS function to find the shortest path
    int bfs(int n, vector<vector<int>>& adjList) {
        vector<bool> visited(n, false); // To keep track of visited nodes
        queue<int> nodeQueue;          // Queue for BFS traversal
        nodeQueue.push(0);
        visited[0] = true;
        int layersExplored = 0;        // Track the number of layers (shortest distance)

        while (!nodeQueue.empty()) {
            int layerSize = nodeQueue.size(); // Process all nodes in the current layer
            for (int i = 0; i < layerSize; ++i) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();

                if (currentNode == n - 1) {
                    return layersExplored; // Found the shortest path
                }

                for (int neighbor : adjList[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodeQueue.push(neighbor);
                    }
                }
            }
            layersExplored++;
        }

        return -1; // Should not reach here if graph is connected
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n);

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        // Track added edges to prevent duplicates
        set<pair<int, int>> existingEdges;

        for (auto& road : queries) {
            int u = road[0];
            int v = road[1];

            // Add the road if it doesn't already exist
            if (existingEdges.count({u, v}) == 0) {
                adjList[u].push_back(v);
                existingEdges.insert({u, v});
            }

            // Perform BFS to find the shortest path after adding the new road
            answer.push_back(bfs(n, adjList));
        }

        return answer;
    }
};
