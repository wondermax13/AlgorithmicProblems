class Solution {
public:
    int subarraySumclass Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int size = nums.size();
        
        if(size == 0) {
            
            return 0;
        }
        
        
        //O(N) - store map of sums and frequencies
        //For each new sum, result += (sum - k)
        
        int count = 0;
        
        unordered_map<int, int> sums;
        
        int sum = 0;
        sums[0] = 1;
        
        for(auto num : nums) {
            
            sum += num;
            
            if(sums.find(sum - k) != sums.end()) {
                
                count += sums[sum - k];
            }
            
            sums[sum]++;
        }
        
        /*
        for(int start = 0; start < size; start++) {
            
            int sum = 0;
            for(int end = start; end < size; end++) {
                
                if(start == end) {
                    
                    sum = nums[start];
                }
                else {
                    sum += nums[end];
                }
                
                if(sum == k) {
                    
                    ++count;
                }
            }
        }*/
        
        
        
        
        
        
        /*
        
        MLE
        
        vector<vector<int>> grid(size, vector<int>(size));
        
        for(int index = 0; index < size; index++) {
            
            grid[index][index] = nums[index];
        }
        
        for(int start = 0; start < size; start++) {
            for(int end = start + 1; end < size; end++) {
                
                grid[start][end] = grid[start][end - 1] + nums[end];
            }
        }
        
        int count = 0;
        for(int start = 0; start < size; start++) {
            for(int end = start; end < size; end++) {
                
                if(grid[start][end] == k) {
                    
                    ++count;
                }
            }
        }
        */
        
        return count;
    }
};(vector<int>& nums, int k) {
        
        int size = nums.size();
        
        if(size == 0) {
            
            return 0;
        }
        
        
        
        int count = 0;
        
        for(int start = 0; start < size; start++) {
            
            int sum = 0;
            for(int end = start; end < size; end++) {
                
                if(start == end) {
                    
                    sum = nums[start];
                }
                else {
                    sum += nums[end];
                }
                
                if(sum == k) {
                    
                    ++count;
                }
            }
        }
        
        /*
        
        MLE
        
        vector<vector<int>> grid(size, vector<int>(size));
        
        for(int index = 0; index < size; index++) {
            
            grid[index][index] = nums[index];
        }
        
        for(int start = 0; start < size; start++) {
            for(int end = start + 1; end < size; end++) {
                
                grid[start][end] = grid[start][end - 1] + nums[end];
            }
        }
        
        int count = 0;
        for(int start = 0; start < size; start++) {
            for(int end = start; end < size; end++) {
                
                if(grid[start][end] == k) {
                    
                    ++count;
                }
            }
        }
        */
        
        return count;
    }
};