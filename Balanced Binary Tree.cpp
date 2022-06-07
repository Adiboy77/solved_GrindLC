class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int hl = height(root->left);
        int hr = height(root->right);
        return abs(hl-hr)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
