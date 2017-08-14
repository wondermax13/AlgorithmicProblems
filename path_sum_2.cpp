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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        vector<int> path;
        if(root != nullptr) {
            checkSum(root, path, res, sum);
        }
        
        return res;
    }
    
    void checkSum(TreeNode* node, vector<int>& path, vector<vector<int>>& res, int target) {
        
        if(target == node->val && node->left == nullptr && node->right == nullptr) {
            
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
        }
        else {
            path.push_back(node->val);
            if(node->left != nullptr) {
                
                checkSum(node->left, path, res, target - node->val);
            }
            if(node->right != nullptr) {
                checkSum(node->right, path, res, target - node->val);
            }
            
            path.pop_back();
        }
    }
};