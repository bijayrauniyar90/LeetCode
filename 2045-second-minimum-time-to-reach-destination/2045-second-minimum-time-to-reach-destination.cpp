class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        min_heap.push({0, 1});
        dist1[1] = 0;

        while (!min_heap.empty()) {
            auto [timeTaken, node] = min_heap.top();
            min_heap.pop();

            if (++freq[node] == 2 && node == n) return timeTaken;

            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken += time;
            }

            for (int neighbor : adj[node]) {
                if (freq[neighbor] == 2) continue;
                if (dist1[neighbor] > timeTaken) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = timeTaken;
                    min_heap.push({timeTaken, neighbor});
                } else if (dist2[neighbor] > timeTaken && dist1[neighbor] != timeTaken) {
                    dist2[neighbor] = timeTaken;
                    min_heap.push({timeTaken, neighbor});
                }
            }
        }
        return -1;
    }
};