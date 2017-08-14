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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* res;
        
        int val_ = root->val;
            
        if(val_ == p->val || val_ == q->val) {
                
            res = root;
        }
        
        
        return findCommonAncestor(root, p, q, res);
        
        //return res;
    }
    
    TreeNode* findCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* res) {
        
        // if(root != nullptr) {
            
            int val_ = root->val;
            
            /*if(val_ == p->val || val_ == q->val) {
                
                //res = root;
                return root;
            }*/
            // else {
                bool p_lesser = val_ > p->val;
                bool q_lesser = val_ > q->val;
            
                /*if(p_lesser != q_lesser) {
                
                    //res = root;
                    return root;
                }*/
            
                if(val_ > p->val && val_ > q->val) {
                
                    return findCommonAncestor(root-> left, p, q, res);
                }
                else if(val_ < p->val && val_ < q->val) {
                    return findCommonAncestor(root-> right, p, q, res);
                }
            // }
        // }
        
        return root;
    }
};