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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        vector<int> vec;
        unordered_map<int, int> sums;
        
        findSubTreeSum(root, sums);
            
        int max = 0;
            
        for(auto sum : sums) {
                
            max = sum.second > max ? sum.second : max;
        }
            
        for(auto sum : sums) {
            if(max == sum.second) {
                    
                vec.push_back(sum.first);
            }
        }
        
        return vec;
    }
    
    int findSubTreeSum(TreeNode* node, unordered_map<int, int>& sums) {
        
        int sum = 0;
        
        if(node != NULL) {
            
            int sum = node->val;
            
            sum += findSubTreeSum(node->left,  sums);
            sum += findSubTreeSum(node->right, sums);
            
            sums[sum]++;
        }
        
        return sum;
    }
};