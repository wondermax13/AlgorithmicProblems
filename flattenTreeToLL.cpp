/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* curr = nullptr;
        
        stack<TreeNode*> s;
        
        if(root != nullptr) {
            s.push(root);
        }
        
        while(!s.empty()) {
            
            TreeNode* top = s.top();
            s.pop();
            
            if(curr != nullptr) {
                
                curr->right = top;
                curr -> left = nullptr;
            }
            
            curr = top;
            
            if(top->right != nullptr) {
                s.push(top->right);
            }
            if(top->left != nullptr) {
                s.push(top->left);
            }
        }
    }
    
    /*
    void recurseBST(TreeNode* node, TreeNode* curr) {
        
        if(node != nullptr) {
            
            curr->right = node;
            curr = node;
            
            recurseBST(node->left, curr);
            recurseBST(node->right, curr);
        }
    }
    */
};