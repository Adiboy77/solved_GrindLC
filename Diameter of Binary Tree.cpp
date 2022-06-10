class Solution {
public:
  // our pair will store two values
//*first will be the diameter value
//*second will be the height value;

pair<int,int> diameter(TreeNode*root)
{
    // base case 
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);
    
    int op1 = left.first;         // this will store the diameter of left Tree
    int op2 = right.first;        // this well store the diameter of right tree;
    int op3 = left.second + right.second;        // here is the height of total tree;
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));// here is max 0f height and diameter ;
    ans.second = max(left.second, right.second) + 1;  // max of height
    return ans;
}
int diameterOfBinaryTree(TreeNode* root) {
    return diameter(root).first;// first stores the diameter of return it ;
}
};
