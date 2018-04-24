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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> view;
        
        getRightView(root, 1, view);
        
        return view;
    }
    
    void getRightView(TreeNode* node, int level, vector<int>& view) {
        
        if(node != nullptr) {
            
            if(view.size() < level) {
                
                view.push_back(node->val);
            }
            
            getRightView(node->right, level + 1, view);
            getRightView(node->left, level + 1, view);
        }
    }
};