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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(root == NULL) {
            
            return result;
        }
        
        vector<int> back;
        back.push_back(root->val);
        result.push_back(back);
        
        addLevelNodes(root, 2, result);
        
        return result;
    }
    
    void addLevelNodes(TreeNode* node, int level, vector<vector<int>>& allLists) {
        
        if(node != NULL && (node-> left != NULL || node->right != NULL)) {
            
            int size = allLists.size();

            vector<int> newVec;
            if(level > size) {
            
                allLists.push_back(newVec);
            }
        
            // vector<int> back = 
        
            if(node->left != NULL) {
        
                allLists.at(level-1).push_back(node->left->val);
            }
        
            if(node->right != NULL) {
                
                allLists.at(level-1).push_back(node->right->val);
            }
        
            addLevelNodes(node->left, level + 1, allLists);
            addLevelNodes(node->right, level + 1, allLists);
        }
    }
};