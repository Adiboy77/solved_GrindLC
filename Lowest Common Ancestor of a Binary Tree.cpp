class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root==p || root==q) 
            return root;
        TreeNode* lr = lowestCommonAncestor(root->left,p,q);
        TreeNode* rr = lowestCommonAncestor(root->right,p,q);
        if((lr && rr) || (lr == root || rr == root))//lr && rr gives true when p and q lie in left and right branches
            return root;
        else if(lr)
            return lr;
        else 
            return rr;
    }
};
