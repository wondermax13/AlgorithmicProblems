class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            
            return false;
        }
        
        int start = 0, end = nums.size() - 1;
        
        while(start < end) {
            
            int mid = (start + end) / 2;
            
            if(nums[mid] == target) {
                return true;
            }
            //Pivot is on the right
            else if(nums[mid] > nums[end]) {
                
                if(nums[mid] > target && nums[start] <= target) {
                    
                    end = mid;
                }
                else {
                    
                    start = mid + 1;
                }
            }
            else if(nums[mid] < nums[end]) {
                
                if(nums[mid] < target && nums[end] >= target) {
                    
                    start = mid + 1;
                }
                else {
                    
                    end = mid;
                }
            }
            else { //nums[mid] == nums[end]
                --end;
            }
        }
        
        return nums[start] == target ? true : false;
    }
};