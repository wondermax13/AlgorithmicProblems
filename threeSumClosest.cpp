class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        int globalThreeSum;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            
            int start = i + 1, end = nums.size() - 1;
            
            while(start < end) {
                
                int three_sum = nums[start] + nums[end] + nums[i];

                int localDiff = abs(target - three_sum);
                
                if( diff > localDiff) {
                    
                    diff = localDiff;
                    globalThreeSum = three_sum;
                }
                
                if(three_sum < target) {
                    
                    ++start;
                }
                else if(three_sum > target) {
                    
                    --end;
                }
                else {
                    
                    return target;
                }
                
            }
        }
        
        return globalThreeSum;
    }
};