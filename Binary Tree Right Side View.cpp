/*
Explanation:
We will push one element at each level. So, the size of the res vector will actually be equal to the number of levels we have already stored the result. If the level of some element is more than the size of res vector that means this will be a new level for which we have not pushed anything in the res vector. So, we will push this element in the res vector. The size of res in next iterations will increase by one and for all the other elements in same level res.size() > level will be false
And you only add one node per level. And this preorder recurs right node first. So at each level you will add rightmost and others will automatically get skipped.
*/
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
