class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        
        // Construct the graph
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        // Max-heap priority queue to maximize probability
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        pq.push({1.0, start});
        
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (node == end) return prob;
            
            if (prob < maxProb[node]) continue;
            
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                
                if (maxProb[node] * edgeProb > maxProb[nextNode]) {
                    maxProb[nextNode] = maxProb[node] * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        
        return 0.0;
    }
};