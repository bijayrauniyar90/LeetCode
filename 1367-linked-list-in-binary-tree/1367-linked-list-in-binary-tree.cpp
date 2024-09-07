class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        // Check for match at current node or in left/right subtrees
        return checkPath(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool checkPath(TreeNode* node, ListNode* head) {
        // If we reached the end of the list, we've found a match
        if (!head) return true;
        // If node is null or values don't match, return false
        if (!node || node->val != head->val) return false;
        // Recursively check both left and right subtrees for a valid path
        return checkPath(node->left, head->next) || checkPath(node->right, head->next);
    }
};
