//https://www.youtube.com/watch?v=i9ORlEy6EsI
/*
For upward traversal, we will mark the parent pointer
We can use hashmap, to store the parent of every nodes
Say if target's value is given, then find the target node by simply searching it in the tree
Additionally, we will carry a visited hash, which will tell which all nodes have been visited.
We maintain this visited hash because at each step(starting from target), we move radially outwards in both directions ie upwards & downwards(while increasing the distance by 1 at each step), so the visited hash ensures that we don't come back to the same node in the next step.
Time: O(N), considering O(1) for unordered_map
Space: O(N)
*/
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};
