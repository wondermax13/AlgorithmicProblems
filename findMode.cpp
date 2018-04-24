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
     
        unordered_map<int, int> counts;
        
        
        populateCounts(root, counts);
        
        int maxCount = 0;
        vector<int> modes;
        
        for(auto p : counts) {
            
            maxCount = max(maxCount, p.second);
        }
        
        for(auto p : counts) {
            
            if(maxCount == p.second) {
                modes.push_back(p.first);
            }
        }
        
        int currVal = INT_MAX, currCount = 0, currMax = 0;
        
        populateMaxs(root, currVal, currCount, currMax, modes);
            
        return modes;
    }
    
    void populateCounts(
        TreeNode* node, unordered_map<int, int>& counts) {
        
        if(node != nullptr) {
            
            counts[node->val]++;
            
            populateCounts(node->left, counts);
            populateCounts(node->right, counts);
        }
    }
    
    void populateMaxs(
        TreeNode* node, int& currVal, int& currCount, int& currMax, vector<int>& counts) {
        
        if(node != nullptr) {
            
            populateMaxs(node->left, currVal, currCount, currMax, counts);
            
            if(currVal == node->val) {
                
                ++currCount;
                
                //currVal is part of counts
                if(find(counts.begin(), counts.end(), node->val) != counts.end()) {
                
                    counts.clear();
                    ++currMax;
                
                    counts.resize(1);
                    counts[0] = node->val;
                }
                else {
                    
                    if(currCount == currMax) {
                        
                        counts.push_back(currVal);
                    }
                }
            }
            else {
                currVal = node->val;
                currCount = 1;
            }
            
            populateMaxs(node->right, currVal, currCount, currMax, counts);
        }
        
    }
};