
/*
    CORRECTED
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int endIndex = -1;
        int startIndex = findStartIndex(nums, target);
        
        
        if(startIndex != -1) {
            
            endIndex = findEndIndex(nums, target, startIndex);
        }
        
        vector<int> range;
        range.push_back(startIndex);
        range.push_back(endIndex);
        
        return range;
    }
    
    int findStartIndex(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1, mid = 0;
        
        bool found = false;
        
        while(start < end && !found) {
            
                mid = (start + end) / 2;
                
                /*if(nums[mid] == target) {
                    
                    end = mid;
                }
                else*/ if(nums[mid] < target) { //INCORRECT SINCE ROTATION HAS NOT BEEN TAKEN INTO ACCOUNT
                    
                    start = mid + 1;
                }
                else {
                    
                    end = mid;
                }
        }
        
        return nums[start] == target ? start : -1;
    }
    
    int findEndIndex(vector<int>& nums, int target, int startIndex) {
        
        int start = startIndex, end = nums.size() - 1, mid = 0;
        
        bool found = false;
        
        while(start < end && !found) {
            
            //Very important. Bias the loop towards right
            mid = (start + end) / 2 + 1;
                
            /*if(nums[mid] == target) {
                    
                start = mid;
            }
            else*/ if(nums[mid] > target) {
                    
                end = mid - 1;
            }
            else {
                    
                start = mid;
            }
        }
        
        return nums[start] == target ? start : -1;
    }
};