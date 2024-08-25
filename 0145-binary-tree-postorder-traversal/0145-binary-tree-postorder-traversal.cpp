/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            TreeNode* currentNode = stack1.top();
            stack1.pop();
            stack2.push(currentNode);

            if (currentNode->left) {
                stack1.push(currentNode->left);
            }
            if (currentNode->right) {
                stack1.push(currentNode->right);
            }
        }

        while (!stack2.empty()) {
            result.push_back(stack2.top()->val);
            stack2.pop();
        }

        return result;
    }
};

