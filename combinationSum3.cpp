class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> curr;
        int currSum = 0;
        
        vector<vector<int>> res;
        
        getCombination(curr, currSum, n, k, res);
        
        return res;
    }
    
    void getCombination(
        vector<int>& curr, int& currSum,
        int sum, int k,
        vector<vector<int>>& res) {
        
        if(curr.size() >= k) {
            
            
            if(currSum == sum) {
                
                res.push_back(curr);
            }
        }
        else {
            int prevVal = curr.size() == 0 ? 0 : curr[curr.size() - 1];
            
            for(int val = prevVal + 1; val < 10; val++) {
                
                if(currSum + val <= sum) {
                    
                    
                    
                    currSum += val;
                    curr.push_back(val);
                    
                    getCombination(curr, currSum, sum, k, res);
                    
                    curr.pop_back();
                    currSum -= val;
                }
            }
        }
    }
};