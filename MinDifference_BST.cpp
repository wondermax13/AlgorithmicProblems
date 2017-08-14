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
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> res;
        stack<TreeNode*> s;
        
        int diff = INT_MAX;
        
        s.push(root);
        
        while(!s.empty() && diff != 0) {
            
            TreeNode* top = s.top();
            s.pop();
            
            
            updateMin(res, top->val, diff);
            
            res.push_back(top->val);
            
            
            if(top->left != nullptr) {
                
                s.push(top->left);
            }
            if(top->right != nullptr) {
                
                s.push(top->right);
            }
        }
        
        return diff;
    }
    
    void updateMin(vector<int> res, int val, int& diff) {
        
        for(int i = 0; i < res.size(); i++) {
            
            diff = min(abs(res[i] - val), diff);
        }
    }
    
    /*
        POPULAR SOLUTION - INORDER TRAVERSAL. COMPARE VAL AND NODE->VAL, VAL = NODE->VAL
        
        void inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        
            if (root->left != NULL) inorderTraverse(root->left, val, min_dif);
            
            if (val >= 0)  //CHECK WHETHER VAL HAS BEEN INITIALIZED DURING TRAVERSAL
                min_dif = min(min_dif, root->val - val);
            
                val = root->val; //SET TO CURRENT NODE->VAL
                
            if (root->right != NULL) 
                inorderTraverse(root->right, val, min_dif);
        }
        
        int getMinimumDifference(TreeNode* root) {
            auto min_dif = INT_MAX, val = -1;
            inorderTraverse(root, val, min_dif);
            return min_dif;
        }
    */
    
    /*void checkDiff(TreeNode* node, int& min_, int& parentVal_) {
        
        if(node != NULL) {
            
            checkDiff(node->left, min_, parentVal_);
            
            if(parentVal_ != INT_MAX) {
                
                min_ = min(min_, node->val - parentVal_);
            }
            
            parentVal_ = (node -> val);
            
            checkDiff(node->right, min_, parentVal_);
            
        }
    }*/
};