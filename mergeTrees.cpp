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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        TreeNode* resNode = merge(t1, t2);
        
        return resNode;
    }
    
    TreeNode* merge(TreeNode* t1, TreeNode* t2) {
        
        TreeNode* resNode = nullptr;
        if(t1 != nullptr && t2 != nullptr) {
            
            int res = t1->val + t2->val;
            
            t1->val = res;
            
            t1->left = merge(t1->left, t2->left);
            t1->right = merge(t1->right, t2->right);
            
            resNode = t1;
        }
        else if(t1 != nullptr && t2 == nullptr) {
            
           resNode = t1;
        }
        else {
            
            resNode = t2;
        }
        
        return resNode;
    }
};