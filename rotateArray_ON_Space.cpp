class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(k == 0) return;
        
        
        
        int size = nums.size();
        
        int q = k/size, r = k%size;
        int x = size - 1 - r;
        
        vector<int> swapper(r);
        
        for(int index = 0; index <= r; index++) {
            
            swapper[index] = nums[index + x];
        }
        
        for(int index = x; index >= 0; index--) {
            
            nums[index + r] = nums[index];
        }
        
        for(int index = 0; index <= r; index++) {
            
            nums[index] = swapper[index];
        }
    }
};class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(k == 0) return;
        
        int size = nums.size();
        
        int currIndex = 0, startIndex = 0;
        int currVal = nums[currIndex];
        
        int totalReplacements = 0;
        
        int target = size - 1;
        int tmp = currVal, val = currVal;
        
        while(totalReplacements < size) {
            
            while(currIndex != startIndex) {
                
                target = (currIndex + k) % size;
                
                tmp = nums[target]; //Save target;
                nums[target] = val;
                
                val = tmp;
                
                currIndex = target;
                
                ++totalReplacements;
            }
            
            ++startIndex;
            currIndex = startIndex;
        }
    }
};