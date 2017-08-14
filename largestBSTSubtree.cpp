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
    
    class BSTP {
    public:    
        int minVal, maxVal;
        bool isBST;
        int size;
    };
    
public:
    int largestBSTSubtree(TreeNode* root) {
        
        int maxSize = 0;
        BSTP res = checkBST(root, maxSize);
        
        return maxSize;
    }
    
    BSTP checkBST(TreeNode* node, int& maxSize) {
        
        BSTP res;
        
        if(node == nullptr) {
            
            res.isBST = true;
            res.minVal = INT_MAX;
            res.maxVal = INT_MIN;
            res.size = 0;
            
            return res;
        }
        /*else if(node ->left == nullptr && node->right == nullptr) { //Leaf node
        
            res.isBST = true;
            res.minVal = node->val;
            res.maxVal = node->val;
            res.size = 1;
            
            maxSize = max(maxSize, res.size);
            
            return res;
        
        }*/
        else { //if(node ->left == nullptr && node->right == nullptr) { //Leaf node
            
            cout << " node->val: " << node->val << endl;
            
            BSTP left = checkBST(node->left, maxSize);
            BSTP right = checkBST(node->right, maxSize);
            
            if(!left.isBST || !right.isBST || left.maxVal >= node->val || right.minVal <= node->val) {
                
                res.isBST = false;
                res.size = 0; //max(left.size, right.size);
                
                res.minVal = 0; //min(node->val , min(left.minVal, right.minVal));
                res.maxVal = 0; //max(node->val , max(left.maxVal, right.maxVal));
                
                cout << " not a BST " << endl;
                
                return res;
            }
            
            else {
                
                int totalSize = left.size + right.size + 1;
                maxSize = max(maxSize, totalSize);/*
                
                bool leftAppend = false, rightAppend = false, append = false;
                
                if(left.isBST && left.maxVal < node->val) {
                    
                    totalSize += leftSize;
                    append = true;
                }
                if(right.isBST && right.minVal > node->val) {
                    
                    totalSize += rightSize;
                    append = true;
                }
                
                if(append) {
                    
                    ++totalSize;
                }

                cout << " leftSize: " << leftSize << " rightSize: " << rightSize << " totalSize: " << totalSize << endl;
                */
                res.isBST = true;
                res.minVal = min(left.minVal, node->val);
                res.maxVal = max(right.maxVal, node->val);
                res.size = totalSize;
            }
        }
        
        return res;
    }
};