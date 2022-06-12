/*
Iterative solution:
bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        while(!queue.empty()) {
            TreeNode *left = queue.front(); queue.pop();
            TreeNode *right = queue.front(); queue.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    }
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; //Tree is empty
        
        return isSymmetricTest(root->left,root->right);
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); //comparing left subtree's left child with right subtree's right child --AND-- comparing left subtree's right child with right subtree's left child
    }
};
