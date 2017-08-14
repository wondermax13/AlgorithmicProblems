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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(0, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* build(
        int preCurr, int inSearchStart, int inSearchEnd,
        vector<int>& preorder, vector<int>& inorder) {
        
        if(!(preCurr < preorder.size()) || inSearchStart > inSearchEnd) {
            
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preCurr]);
        
        int rootIndex = findRootIndexInorder(preorder[preCurr], inSearchStart, inSearchEnd, inorder);
        
        root->left = build(preCurr + 1, inSearchStart, rootIndex - 1, preorder, inorder);
        root->right = build(preCurr + (rootIndex - inSearchStart) + 1, inSearchStart, rootIndex - 1, preorder, inorder);
        
        return root;
    }
    
    int findRootIndexInorder(int rootVal, int inSearchStart, int inSearchEnd, vector<int>& inorder) {
        
        int index = 0;
        
        for(int i = inSearchStart; i <= inSearchEnd; i++) {
            
            if(rootVal == inorder[i]) {
                
                index = i;
            }
        }
        
        return index;
    }
};