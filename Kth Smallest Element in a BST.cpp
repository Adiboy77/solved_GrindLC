/*
Follow up solution:
2. Binary Search: Time ~ O(NlogN), Space ~ O(1)
Binary search based on the size of each left node, where the size is the number of subtree nodes (including the root itself):
if n + 1 == k, the kth node is the root;
if n + 1 < k, the kth node is in the right subtree;
if n + 1 > k, the kth node is in the left subtree.
Binary search takes O(logN); obtaining size takes O(N).
public int kthSmallest(TreeNode root, int k) {
    int n = size(root.left);
    if (n + 1 == k) {
        return root.val;
    } else if (n + 1 < k) {
        return kthSmallest(root.right, k - n - 1);
    } else // if (n + 1 > k) 
    {
        return kthSmallest(root.left, k);
    }
}

private int size(TreeNode x) {
    if (x == null)  return 0;
    return size(x.left) + size(x.right) + 1;
}
Modify BST node's structure:
If the TreeNode class contains size N, the search only takes O(logN).
Below we give the modified class:
public class TreeNode {
    int val;
    int N;  // number of nodes in subtree (including itself)
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public int size(TreeNode x) {
    if (x == null)  return 0;
    return x.N;
}

public void put(int val) {
    root = put(root, val);
}

private TreeNode put(TreeNode x, int val) {
    if (x == null) return new TreeNode(val);
    if (val < x.val)        x.left = put(x.left, val);
    else if (val > x.val)   x.right = put(x.right, val);
    else                    x.val = val;
    x.N = 1 + size(x.left) + size(x.right); // update size
    return x;
}

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
    while (true) 
    {
      while (root != NULL) 
      {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      k--;
      if (k == 0) 
          return root->val;
      root = root->right;
        }
    }
};
