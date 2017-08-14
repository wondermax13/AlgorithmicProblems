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
    int closestValue(TreeNode* root, double target) {
        
        if(root == NULL) {
            
            return 0;
        }
        
        if(root->val == target) {
            
            return target;
        }
        
        if( (root->left == NULL && root->val > target)
        || (root->right == NULL && root->val < target)) {
            
            return root->val;
        }
        
        int searchVal = 0;
        
        if(root->val > target) {
            
            searchVal = closestValue(root->left, target);
        }
        else {
            
            searchVal = closestValue(root->right, target);
        }
        
        int uniqueVal = abs(searchVal - target) < abs(root->val - target) ? searchVal : root->val;
        
        return uniqueVal;
    }
};