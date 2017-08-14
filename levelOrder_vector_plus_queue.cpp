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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root != nullptr) {
            
            deque<TreeNode*> q_;
        
            q_.push_back(root);
            
            while(!q_.empty()) {
                
                int currLevelSize = q_.size(); //Trick - store the no. of nodes in the current level
                
                vector<TreeNode*> v_;
                
                /*while(!q_.empty()) {
                    
                    v_.push_back(q_.front());
                    q_.pop_front();
                }*/
                
                //q_.clear();
                
                vector<int> vec_;
                
                for(int i = 0; i < currLevelSize; i++) {
                    
                    TreeNode* node = q_.front();
                    q_.pop_front();
                    
                    if(node != nullptr) {
                        
                        vec_.push_back(node->val);
                        
                        if(node->left != nullptr) {
                            
                            q_.push_back(node->left);
                        }
                        if(node->right != nullptr) {
                            
                            q_.push_back(node->right);
                        }
                    }
                    
                }
                
                res.push_back(vec_);
            }
        }
        
        return res;
    }
};