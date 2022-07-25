class Solution {
public:
    /*
        // the minimum value in right subtree is inorder successor or inorder successor can also be called as the next node in the inorder of that tree.
        // the maximum value in left subtree is inorder predecessor or inorder predecessor can also be called as the previous node in the inorder of that tree.
    */
     /*
     Iterative:
      TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        TreeNode * fa = NULL;
        while (root && root != p) {
            if (root->val < p->val)
                root = root->right;
            else {
                fa = root;
                root = root->left;
            }
        }
        
        if (root == NULL)
            return NULL;
        if (root->right == NULL)
            return fa;
            
        root = root->right;
        while (root->left)
            root = root->left;
        return root;
    }
     */
      TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if (root == NULL)
            return NULL;
        
        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);
        
        TreeNode * left = inorderSuccessor(root->left, p);
        return left ? left : root;
    }
};
