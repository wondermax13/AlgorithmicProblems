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
    int kthSmallest(TreeNode* root, int k) {
        
        int result = 0;
        findKth(root, k, result);
        
        return result;
    }
    
    void findKth(TreeNode* node, int& k, int& result) {
        
        //Need to do this to avoid NPE
        if(node == NULL) {
            
            return;
        }
        
        //TreeNode* leftSearch = NULL, rightSearch = NULL;
        
        if(node->left != NULL) {
            
            findKth(node->left, k, result);
        }
        
        //Additional check at the end of left search
        if(k == 0) {
            
            return;
        }
        
        --k;

        if(k == 0) {
                
            result = node->val;
            return;
        }
      
        if(node->right != NULL) {
            
            findKth(node->right, k, result);
        }
    }
};