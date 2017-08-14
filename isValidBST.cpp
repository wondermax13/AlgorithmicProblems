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
    bool isValidBST(TreeNode* root) {
        
        if(root == nullptr) {
            
            return true;
        }
        
        return checkRange(root, nullptr, nullptr);
    }
    
    //Use pointers to not check min/max for root value since it should not have any bounds
    bool checkRange(TreeNode* node, int* min_, int* max_) {
        
        if(node == nullptr) {
            
            return true;
        }
        
        if((max_ != nullptr && node->val >= *max_) || (min_ != nullptr && node->val <= *min_)) {
            
            return false;
        }
        
        bool leftCheck = checkRange(node->left, min_, &(node->val));
        if(!leftCheck) return false;
        
        bool rightCheck = checkRange(node->right, &(node->val), max_);
        if(!rightCheck) return false;
        
        
        return true;
    }
};