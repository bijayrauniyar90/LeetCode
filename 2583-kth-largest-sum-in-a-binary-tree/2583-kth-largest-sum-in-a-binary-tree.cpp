class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        // Min heap to maintain the top k largest sums
        priority_queue<long, vector<long>, greater<long>> minHeap;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();  // Track the current level size
            long sum = 0;  // Initialize sum for the current level
            
            // Traverse the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfsQueue.front();
                bfsQueue.pop();
                sum += node->val;
                
                // Push children to the queue for the next level
                if (node->left) bfsQueue.push(node->left);
                if (node->right) bfsQueue.push(node->right);
            }
            
            // Maintain only k largest sums in the min heap
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }

        // If we have fewer than k levels
        if (minHeap.size() < k) return -1;
        
        return minHeap.top();  // kth largest sum is at the top of the heap
    }
};
