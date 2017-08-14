class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size < 2) return -1;
        
        int fast = nums[nums[0]];
        int slow = nums[0];
        
        //Find point within the circle
        while(fast != slow) {
            
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        
        //Find the entrance of circle(loop) on the linked list
        while(fast != slow) {
            
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};