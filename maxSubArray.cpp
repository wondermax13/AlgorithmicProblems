class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int size = nums.size();
        vector<vector<int>> vals(size, vector<int>(size));
        
        for(int index = 0; index < size; index++) {
            
            vals[index][index] = nums[index];
        }
        
        for(int len = 2; len <= size; len++) {
            
            for(int startIndex = 0; startIndex < size - (len-1); startIndex++) {
            
            int endIndex = startIndex + (len - 1);
            
            vals[startIndex][endIndex]
                = 
                      max(vals[startIndex+1][endIndex] * nums[startIndex],
                          vals[startIndex][endIndex-1] * nums[endIndex]);
            }
        }
        
        int maxVal = INT_MIN;
        
        for(int row = 0; row < size; row++) {
            for(int col = 0; col < size; col++) {
                
                maxVal = max(maxVal, vals[row][col]);
            }
        }
        
        return maxVal; //vals[0][size - 1];
    }
};

/* ACCEPTED SOLUTION*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int size = nums.size();
        
        int maxHereBack = nums[0], minHereBack = nums[0];
        int maxAll = maxHereBack, maxHere, minHere;
        
        for(int index = 1; index < size; index++) {
            
            maxHere = max(nums[index],
                        max(maxHereBack * nums[index], minHereBack * nums[index]));

            //Used since current value might be negative,
            //Current min with high absolute value might be used later
            minHere = min(nums[index],
                        min(maxHereBack * nums[index], minHereBack * nums[index]));
                        
            maxAll = max(maxAll, maxHere);
            
            maxHereBack = maxHere;
            minHereBack = minHere;
        }
        
        return maxAll;
    }
};
