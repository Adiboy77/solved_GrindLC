/*
Time complexity : \mathcal{O}(N)O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : \mathcal{O}(\log(N))O(log(N)) in the best case of completely balanced tree and \mathcal{O}(N)O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val != q->val)//was wrongly comparing like p != q here
            return false;
        bool flagL = isSameTree(p->left,q->left);
        bool flagR = isSameTree(p->right,q->right);
        return flagL&&flagR;
    }
};
