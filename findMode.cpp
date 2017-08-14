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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        
        int lastVal = -1;
        int count = 0, maxCount = 0;
        
        recurseInorder(root, lastVal, count, maxCount, res);
        
        return res;
    }

    //MORRIS TRAVERSAL !!! IMPORTANT
    private void inorder(TreeNode root) {
        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                handleValue(node.val);
                node = node.right;
            } else {
                TreeNode prev = node.left;
                while (prev.right != null && prev.right != node)
                    prev = prev.right;
                if (prev.right == null) { //CASE BEFORE MODIFYING THE TREE
                    prev.right = node;
                    node = node.left;
                } else {                  //CASE AFTER REVERTING THE TREE (HERE PREV.RIGHT == NODE)
                    prev.right = null;
                    handleValue(node.val);
                    node = node.right;
                }
            }
        }
    }
    
    void recurseInorder(
        TreeNode* node, int &lastVal, int& count,
        int& maxCount, vector<int>& res) {
            
        if(node != nullptr) {
            
            recurseInorder(node->left, lastVal, count, maxCount, res);
            
            //This won't fail if left most node is -1
            //count = 1 > maxCount
            //So res.push_back(-1)
            if(node->val == lastVal) {
                
                ++count;
            }
            else {
                lastVal = node->val;
                count = 1;
            }
            
            if(count == maxCount) {
                    
                    res.push_back(node->val);
            }
            else if(count > maxCount) {
                    
                    res.clear();
                    res.push_back(node->val);
                    maxCount = count;
            }
            
            recurseInorder(node->right, lastVal, count, maxCount, res);
        }
    }
};