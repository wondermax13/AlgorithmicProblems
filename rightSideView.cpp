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
        
        int currLevel = 1;
        recurse(root, view, currLevel);
        
        return view;
    }
    
    void recurse(TreeNode* node, vector<int>& view, int& currLevel) {
        
        if(node != nullptr) {
            
            cout << " node: " << node->val << " currLevel: " << currLevel << endl;
            
            if(currLevel > view.size()) {
                
                view.push_back(node->val);
            }
            
                ++currLevel;
                
                recurse(node->right, view, currLevel);
                recurse(node->left, view, currLevel);
                
                --currLevel;
        }
    }
};