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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root != nullptr) {
            
            deque<TreeNode*> q_;
        
            q_.push_back(root);
            
            bool right_to_left = false;
            
            while(!q_.empty()) {
                
                int currLevelSize = q_.size(); //Trick - store the no. of nodes in the current level
                
                vector<TreeNode*> v_;
                
                /*while(!q_.empty()) {
                    
                    v_.push_back(q_.front());
                    q_.pop_front();
                }*/
                
                //q_.clear();
                
                vector<int> vec_(currLevelSize);
                
                for(int i = 0; i < currLevelSize; i++) {
                    
                    TreeNode* node = q_.front();
                    q_.pop_front();
                    
                    if(node != nullptr) {
                        
                        
                        int target = right_to_left ? currLevelSize - 1 - i : i;
                        vec_[target] = (node->val);
                        
                        if(node->left != nullptr) {
                            
                            q_.push_back(node->left);
                        }
                        if(node->right != nullptr) {
                            
                            q_.push_back(node->right);
                        }
                    }
                    
                }
                
                right_to_left = !right_to_left;
                
                res.push_back(vec_);
            }
        }
        
        return res;
    }
};