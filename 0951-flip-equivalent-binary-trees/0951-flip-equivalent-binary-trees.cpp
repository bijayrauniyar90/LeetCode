class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base case: both trees are empty
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // Base case: one tree is empty or values differ
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }
        
        // Check if subtrees are equivalent either with or without flipping
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
