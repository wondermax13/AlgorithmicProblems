class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> ranges;
        
        if(nums.size() != 0) {
            
            int startIndex = 0, endIndex = nums.size() - 1;
            
            if(nums[startIndex] != lower) {
                
                createRange(lower, nums[startIndex] - 1, ranges);
            }
            
            for(int index = 0; index < nums.size() - 1; index++) {
                
                if(nums[index] + 2 <= nums[index + 1]) {
                    createRange(nums[index] + 1, nums[index + 1] - 1, ranges);
                }
            }
            
            if(nums[endIndex] != upper) {
                
                createRange(nums[endIndex] + 1, upper, ranges);
            }
        }
        else {
            
            createRange(lower, upper, ranges);
        }
        
        return ranges;
    }
    
        void createRange(int bound1, int bound2, vector<string>& ranges) {
        
        if(bound1 <= bound2) {
            string range =
                bound1 == bound2 ? to_string(bound1) : to_string(bound1).append("->").append(to_string(bound2));

            ranges.push_back(range);
        }
    }
    
    void createRange_mine(int bound1, int bound2, vector<string>& ranges) {
        
        if(bound2 > bound1 + 1) {
            
            string range = to_string(bound1 + 1);
            
            if(bound2 > bound1 + 2) {
                
                range.append("->");
                range.append(to_string(bound2 - 1));
            }
            
            ranges.push_back(range);
        }
    }
};