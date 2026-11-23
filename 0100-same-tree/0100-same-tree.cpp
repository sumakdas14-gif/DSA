class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null: structurally identical at this leaf
        if (!p && !q) return true;
        
        // One node is null or values differ: not identical
        if (!p || !q || p->val != q->val) return false;
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};