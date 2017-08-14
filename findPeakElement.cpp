class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 0) {
            return -1;
        }
        else if(size == 1) {
            
            return 0;
        }
        
        
        if(nums[1] < nums[0]) {
            
            return 0;
        }
        
        bool found = false;
        int index = 1, target = -1;
        
        while(index < size-1 && !found) {
            
            found = (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]);
                
            if(found) {
                target = index;
            }
            
            ++index;
        }
        
        if(!found && nums[size-2] < nums[size-1]) {
            
            target = size - 1;
        }
        
        
        return target;
    }
};

/*

                    BINARY SEARCH

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 0) {
            return -1;
        }
        else if(size == 1) {
            
            return 0;
        }
        
        
        if(nums[1] < nums[0]) {
            
            return 0;
        }
        
        bool found = false;
        int index = 1, target = -1;
        
        int start = 0, end = size - 1;
        
        while(start < end && !found) {
            
            index = (start + end) / 2;
            
            if(nums[index] <= nums[index - 1]) {
                
                end = index;
            }
            else if(nums[index] <= nums[index + 1]) {
                start = index + 1;
            }
            else {
                found = true;
            }
                
            if(found) {
                target = index;
            }
            
            ++index;
        }
        
        if(!found && nums[size-2] < nums[size-1]) {
            
            target = size - 1;
        }
        
        
        return target;
    }
};


*/






