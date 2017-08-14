class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            return -1;
        }
        
        int start = 0, end = nums.size() - 1, index = -1;
        
        int count = 0;
        while(start < end) {
            
            int mid = (start + end) / 2;
            
            if(nums[mid] > nums[end]) {
                
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        int origin = start;
        int realMid = (origin + nums.size() /  2) % (nums.size());
        
        int startReal = 0; // origin;
        int endReal = nums.size() - 1; // (origin + nums.size()) % (nums.size()) - 1;
        while(startReal <= endReal) {
            
            int mid = (startReal + endReal) / 2;
            
            realMid = (mid + origin) % (nums.size());
            if(nums[realMid] == target) return realMid;
            
            else if(nums[realMid] < target) {
                
                startReal = mid + 1;
                
            }
            else {
                
                endReal = mid - 1;
            }
        }
        
        return -1;
    }
};