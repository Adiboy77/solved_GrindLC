//Code while never pushing NULL in the queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> result;
      if (!root) return result;

      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty()) 
      {
          int n = q.size();
          vector<int> crtLevel;
          for (int i = 0; i < n; i++)//As n == current queue size, so this for loop ensures right amount of elements at each level in the level order traversal
          {
              TreeNode *p = q.front();
              q.pop();
              crtLevel.push_back(p->val);
              if (p->left) q.push(p->left);
              if (p->right) q.push(p->right);
          }
          result.push_back(crtLevel);
      }
      return result;
    }
};
