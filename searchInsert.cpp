class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1, targetIndex = -1;
        bool found = false;
        
        while(start <= end && !found) {
            
            int pivot = (start + end) / 2;
            
            if(nums[pivot] == target) {
                
                // found = true;
                targetIndex = pivot;
                
                return targetIndex;
            }
            else if(nums[pivot] > target) {
                end = pivot - 1;
            }
            else {
                start = pivot + 1;
            }
        }
        
        if(!found) {
            targetIndex = start;
        }
        
        return targetIndex;
    }
};