class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n+1, 0);
        
        // Compute the prefix XOR array
        for (int i = 0; i < n; ++i) {
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }
        
        vector<int> result;
        // Process each query in constant time
        for (const auto& q : queries) {
            result.push_back(prefixXor[q[1] + 1] ^ prefixXor[q[0]]);
        }
        
        return result;
    }
};
