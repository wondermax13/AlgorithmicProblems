class Solution {
public:
    bool splitArray(vector<int>& nums) {
        
        bool result = false;
        int n = nums.size();
        
        vector<int> totalSum(n);
        
        populateTotalSum(nums, totalSum);
        
        for(int i = 1; i < n; i++) {
            
            int sum1 = findSum(0, i-1, totalSum);
            
            for(int j = i+2; j <= n-4; j++) {
                
                int sum2 = findSum(i, j-1, totalSum);
                
                if(sum1 == sum2) {
                    
                    for(int k = j+2; k <= n-2; k++) {
                        
                        int sum3 = findSum(j, k-1, totalSum);
                        
                        if(sum2 == sum3 && sum2 == findSum(k, n-1, totalSum)) {
                            return true;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    int findSum(int start, int end, vector<int>& totalSum) {
        
        if(start == 0) {
            
            return totalSum[end];
        }
        
        return totalSum[end] - totalSum[start];
    }
    
    void populateTotalSum(vector<int> nums, vector<int>& totalSum) {
        
        totalSum[0] = nums[0];
        
        for(int index = 1; index < nums.size(); index++) {
            
            totalSum[index] = totalSum[index - 1]  + nums[index];
        }
    }
};