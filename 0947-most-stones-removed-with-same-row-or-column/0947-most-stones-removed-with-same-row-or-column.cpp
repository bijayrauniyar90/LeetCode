class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n), rank(n, 0);

        // Initialize each stone as its own parent (i.e., each stone is in its own set)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Find the representative of the set
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union two sets
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        // Union stones that share the same row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }

        // Count the number of unique connected components
        int numOfConnectedComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus the number of connected components
        return n - numOfConnectedComponents;
    }
};

