/*
Striver notes: see the desktop SS as well
Gives the maximum number of nodes between any 2 nodes at a level : last level?
So we think of a level order traversal
We will assign nodes (to hypothetical nodes in middle as well) as 1,2,3,4, .. starting from root 
And width = last node - first node at that level + 1
In 0based indexing, if i is parent, then left is 2i+1 and right is 2i+2, and in based it is 2i for left, and 2i+1 for right
But say it is a skewed tree of say length 10^5, then 2i will give as 2*10^5 which is an overflow in arrays:
To avoid overflows, we would do each child as = leftData - min(rightData,leftData),  rightData = rightData - min(leftData,rightData)
So we take a queue of pair<int,int> , first gives node's original value and second gives the indexing that we are doing.
And we take max at each level because there can be cases when width is maximum not at last level but at some intermediate level, like: 1,3,2,5, maxwidth is 2
*/
typedef long long int lli;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if (!root)
            return 0;
      int ans = 0;
      queue<pair<TreeNode*,int>> q;
      q.push({root,0});
      while (!q.empty()) 
      {
        lli size = q.size();
        lli curMin = q.front().second;
        lli leftMost, rightMost;
        for (lli i = 0; i < size; i++) //for each level
        {
          lli cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
          TreeNode* temp = q.front().first;
          q.pop();
          if (i == 0) //first node of the level
              leftMost = cur_id;
          if (i == size - 1) //last node of the level
              rightMost = cur_id;
          if (temp -> left)
            q.push({temp -> left,cur_id * 2 + 1});
          if (temp -> right)
            q.push({temp -> right,cur_id * 2 + 2});
        }
          if(rightMost - leftMost + 1 > ans)//taking max at each level
              ans = rightMost - leftMost + 1;
      }
      return ans;
    }
};
