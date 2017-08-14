class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty()) {
            
            return 0;
        }
        
        if(nums.size() == 1) {
            
            return 1;
        }
        
        int index = 1,
            newIndex = 0;
        
        while(index < nums.size()) {
            
            if(nums[index] == nums[newIndex]) {
                
                index++;
            }
            else {
                newIndex++;
                nums[newIndex] = nums[index];
                index++;
            }
        }
        
        return newIndex + 1;
    }
};

//Max. 2 duplicates allowed
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty()) {
            
            return 0;
        }
        
        if(nums.size() <= 2) {
            
            return nums.size();
        }
        
        int index = 1,
            newIndex = 0,
            count = 1;
        
        while(index < nums.size()) {
            
            if(nums[index] == nums[newIndex]) {
                
                if(count >= 2) {
                    
                    //Ignore
                    index++;
                }
                else {
                    newIndex++;
                    nums[newIndex] = nums[index];
                    index++;
                    
                    ++count;
                }
            }
            else {
                newIndex++;
                nums[newIndex] = nums[index];
                index++;
                count = 1;
            }
        }
        
        return newIndex + 1;
    }
};