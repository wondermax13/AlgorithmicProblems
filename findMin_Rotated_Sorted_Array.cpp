class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int size = nums.size();
        
        int start = 0, end = size - 1;
        
        while(start < end) {
            
            if(nums[start] <= nums[end] ) {
                
                return nums[start];
            }
            int pivot = (start + end)/2;
            
            if(nums[pivot] < nums[start]) {
                
                end = pivot;
            }
            else {
                start = pivot + 1;
            }
        }
        
        return nums[start];
    }
};