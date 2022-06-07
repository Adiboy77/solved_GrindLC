class Solution {
public:
    /*Iterative Solution:
      while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return root;
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root) 
            return root;
        if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val))
            return root;
        else if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left,p,q);
        else
            return lowestCommonAncestor(root->right,p,q);
    }
};
