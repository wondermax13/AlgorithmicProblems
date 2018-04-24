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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> result;
            
        int height = getTreeHeight(root);
        
        if(height > 0) {
            
            result.resize(height);
            
            updatelevelOrder(root, 0, result);
        }
        
        return result;
    }
    
    void updatelevelOrder(
        TreeNode* node, int level, vector<vector<int>>& result) {
        
        if(node != nullptr) {
            
            result[result.size() - 1 - level].push_back(node->val);
            
            updatelevelOrder(node->left, level + 1, result);
            updatelevelOrder(node->right, level + 1, result);
        }
    }
    
    int getTreeHeight(
        TreeNode* node) {
        
        int result = 0;
        
        if(node != nullptr) {
            
            result = 1 + max(getTreeHeight(node->left), getTreeHeight(node->right));
        }
        
        return result;
    }
};