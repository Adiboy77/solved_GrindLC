class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* ln = root->left, *rn = root->right;
       // TreeNode* rn = root->right;
        root->left = invertTree(rn);
        root->right = invertTree(ln);
        return root;
    }
};
