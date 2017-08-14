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
    int rob(TreeNode* root) {
        
        return max(findSum(root, true), findSum(root, false));
    }
    
    /*
        We are solving repeated sub-problems here.
        Better to store values in hashMap
    */
    int findSum(TreeNode* root, bool choose) {
        
        if(root == NULL) {
            
            return 0;
        }
        
        int leftSum = 0, rightSum = 0;
        
        if(!choose) {
            
            leftSum = max(findSum(root-> left, true), findSum(root-> left, false));
            rightSum = max(findSum(root-> right, true), findSum(root-> right, false));
        }
        else {
            leftSum = findSum(root-> left, false);
            rightSum = findSum(root-> right, false);
        }
        
        
        int rootVal = choose ? root->val : 0;
        
        return leftSum + rightSum + rootVal;
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*, int> map_;
        return max(findSum(root, map_), findSum(root, map_));
    }
    
    int findSum(TreeNode* root, unordered_map<TreeNode*, int>& map_) {
        
        if(root == NULL) {
            
            return 0;
        }
        
        unordered_map<TreeNode*, int>::const_iterator pair_ = map_.find(root);
        
        if(pair_ != map_.end()) {
            
            return pair_ -> second;
        }
        
        int chooseRootSum = 0;
        
        if(root->left != NULL) {
            chooseRootSum += max(findSum(root-> left->left, map_), findSum(root-> left->right, map_));
        }
        if(root->right != NULL) {
            chooseRootSum += max(findSum(root-> right->left, map_), findSum(root-> right->right, map_));
        }
        
        int rootVal = max(chooseRootSum + root->val, findSum(root-> left, map_) + findSum(root-> right, map_));
        
        map_.insert(make_pair((TreeNode*)root, rootVal));
        
        return rootVal;
    }
};