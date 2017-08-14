class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        unordered_map<int, int> map_;
        
        int size = nums.size();
        
        //sort nums
        sort(nums.begin(), nums.end());
        
        int start = 0, end = size - 1, mid = 0, count = 0;
        
        while(start < size) {
            
            end = size - 1;
            
            while(end > start) {
                
                mid = start + 1;
                while(mid < end && nums[mid] < target - nums[start] - nums[end]) {
                    
                    ++count;
                    ++mid;
                }
                
                --end;
            }
            
            ++start;
        }
        
        return count;
    }
};