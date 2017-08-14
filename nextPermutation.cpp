class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() > 1) {
            
            int lastIncreasingIndex = getLowestIndex(nums);
            
            if(lastIncreasingIndex == -1) {
                
                reverse(0, nums.size() - 1, nums);
            }
            else {
                
                int leadingVal = nums[lastIncreasingIndex - 1];
                
                int nextHighestIndex = lastIncreasingIndex;
                
                while(
                    nextHighestIndex < nums.size() && nums[nextHighestIndex] > leadingVal) {
                    
                    
                    ++nextHighestIndex;
                }
                
                --nextHighestIndex;
                
                cout << " nextHighestIndex: " << nums[nextHighestIndex] << endl;
                
                nums[lastIncreasingIndex - 1] = nums[nextHighestIndex];
                
                nums[nextHighestIndex] = leadingVal;
                
                reverse(lastIncreasingIndex, nums.size() - 1, nums);                
            }
        }
        
    }
    
    void reverse(
        int start, int end, vector<int>& nums) {
        
        while(start < end) {
            
            int p = nums[start];
            nums[start] = nums[end];
            nums[end] = p;
            
            ++start;
            --end;
        }
    }
    
    int getLowestIndex(vector<int>& nums) {
        
        int lastIncreasingIndex = -1;
            
        int index = 1;
            
        while(index < nums.size()) {
            
            if(nums[index - 1] < nums[index]) {
                lastIncreasingIndex = index;
            }
                
            ++index;
        }
        
        if(lastIncreasingIndex != -1) {
            cout << " lastIncreasingIndex: " << nums[lastIncreasingIndex] << endl;
        }
        
        return lastIncreasingIndex;
    }
};