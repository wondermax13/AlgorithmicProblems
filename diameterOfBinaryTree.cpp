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
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        int maxPathLength = 0;
        
        if(root != nullptr) {
            
            //THE PATH NEED NOT ALWAYS GO THRU ROOT !!!
            height(root, maxPathLength); //->left) + height(root->right);
        }
        
        return maxPathLength;
    }
    
    int height(TreeNode* node, int& maxPathLength) {
        
        int high = 0;
        if(node != nullptr) {
            
            //THIS CASE IS TAKEN CARE OF IN NODE == nullptr CASE IN height()
            /*if(node->left == nullptr && node->right == nullptr) {
                
                high = 1;
            }
            else {*/
                
                int leftHeight = height(node->left, maxPathLength);
                int rightHeight = height(node->right, maxPathLength);
                
                //UPDATE MAX PATH LENGTH
                maxPathLength = max(maxPathLength, leftHeight + rightHeight);
                
                //RETURN HEIGHT
                high = 1 + max(leftHeight, rightHeight);
            //}
        }
        
        return high;
    }
};