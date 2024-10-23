class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        root->val = 0;  // Root has no cousins

        // Start BFS traversal
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int levelSum = 0;

            // First, calculate the sum of the current level nodes
            vector<TreeNode*> currentLevelNodes;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentLevelNodes.push_back(currentNode);

                if (currentNode->left) {
                    levelSum += currentNode->left->val;
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    levelSum += currentNode->right->val;
                    nodeQueue.push(currentNode->right);
                }
            }

            // Second, update each node's children to be the sum of the current level minus its siblings' values
            for (auto node : currentLevelNodes) {
                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) node->left->val = levelSum - siblingSum;
                if (node->right) node->right->val = levelSum - siblingSum;
            }
        }

        return root;
    }
};
