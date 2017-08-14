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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>>allPaths;
        
        if(root == NULL) {
            
            return allPaths;
        }
        
        findSumPaths(root, sum, 0, allPaths);
        
        return allPaths;
    }
    
    vector<int> findSumPaths(TreeNode* node, int sum, int currSum, vector<vector<int>>& childLists) {
        
        vector<int> leftPaths, rightPaths;
        if(node == NULL) {
            
            vector<int> p;
            return p;
        }
        
        if(isLeaf(node) && (sum == currSum + node -> val)) {
            
            //Create a new list with this node. Append it to childLists
            vector<int> newPath;
            newPath.push_back(node -> val);
            childLists.push_back(newPath);
            
            vector<int> index;
            index.push_back(childLists.size() -1);
            
            return index;
        }
        
        
        else {
            leftPaths = findSumPaths(node->left, sum, currSum + node -> val, childLists);
            rightPaths = findSumPaths(node->right, sum, currSum + node -> val, childLists);
            
            leftPaths.insert(leftPaths.end(), rightPaths.begin(), rightPaths.end());
        }
        
        for(index : leftPaths) {
            
            childLists.at(index).push_back(node -> val);
        }
        
        return leftPaths;
    }
    
    bool isLeaf(TreeNode* node) {
        
        return node->left == NULL && node->right == NULL;
    }
};