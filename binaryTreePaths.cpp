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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> result;
        
        string curr;
        
        updateTreePaths(root, curr, result);
        
        return result;
    }
    
    void updateTreePaths(
        TreeNode* node, string curr, vector<string>& paths) {
        
        if(node != nullptr) {
            
            if(curr.size() == 0) {
                
                curr = to_string(node->val);
            }
            else {
                curr += "->";
                curr += to_string(node->val);
            }
            
            if(node->left == nullptr && node->right == nullptr) {
                paths.push_back(curr);
            }
            
            updateTreePaths(node->left, curr, paths);
            updateTreePaths(node->right, curr, paths);
        }
    }
};