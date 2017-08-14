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
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;
        return greaterTree(root, sum);
    }
    
    TreeNode* greaterTree(TreeNode* node, int& sum) {
        
        TreeNode* tn = nullptr;
        if(node != nullptr) {
            
            tn = new TreeNode(0);
            
            tn->right = greaterTree(node->right, sum);
            
            sum += node->val;
            tn-> val = sum;
            
            tn->left = greaterTree(node->left, sum);
        }
        
        return tn;
    }
};