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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int> res;
        
        stack<int> rightRes;
        
        if(root != nullptr) {
            
            res.push_back(root->val);
            leftBoundary(root->left, res);
            
            int leftEnd = res[res.size() - 1];
            leaves(root, res, leftEnd);
            
            int rightEnd = res[res.size() - 1];
            rightBoundary(root, rightRes, rightEnd, root->val, res);
            
            
            while(!rightRes.empty()) {
                
                int top = rightRes.top();
                res.push_back(top);
                rightRes.pop();
            }
        }
        
        return res;
    }
    
    void leftBoundary(TreeNode* root, vector<int>& res) {
        
        TreeNode* curr = root;
        while(curr != nullptr) {
            
            res.push_back(curr->val);
            curr = curr->left != nullptr ? curr->left : curr->right;
        }
    }
    
    void leaves(TreeNode* node, vector<int>& res, int leftEnd) {
        
        if(node != nullptr) {
            
            if(node->left == nullptr && node->right == nullptr) {
                
                if(node->val != leftEnd) {
                    
                    res.push_back(node->val);
                }
            }
            else {
                
                leaves(node->left, res, leftEnd);
                leaves(node->right, res, leftEnd);
            }
        }
    }
    
    void rightBoundary(TreeNode* root, stack<int>& right_res, int finalLeaf, int rootVal, vector<int>& res) {
        
        TreeNode* curr = root;
        while(curr != nullptr) {
            
            if(find(res.begin(), res.end(),curr->val) == res.end()) { // != finalLeaf && curr->val != rootVal) {
                right_res.push(curr->val);
            }
            
            curr = curr->right != nullptr ? curr->right : curr->left;
        }
    }
};