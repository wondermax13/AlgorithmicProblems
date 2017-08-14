class Solution {
public:

    /*
        Here no. of ways to find sum with + or - for S is equal to number of ways with + for (S + totalSum) / 2

    */

    int findTargetSumWays(vector<int>& nums, int S) {
        
        int range = 0;
        
        for_each(nums.begin(), nums.end(), [&range](int num) {
            
            range += num;
        });
        
        vector<int> ways = vector<int>(2*range + 1, 0);
        vector<int> oldWays = vector<int>(2*range + 1, 0);
        
        for_each(nums.begin(), nums.end(), [this, &oldWays, range](int num) {
            
            oldWays[findIndex(num,range)] = 1;
        });
        
        for(int num = 0; num < nums.size(); num++) {
            
            int number = nums[num];
            
            for(int index = range; index - number > 0; index--) {
                
                ways[findIndex(index, range)] += oldWays[findIndex(index-number, range)];
            }
            
            for(int index = 0; index + number < range; index++) {
                
                ways[findIndex(index, range)] += oldWays[findIndex(index+number, range)];
            }
            
            ways = oldWays;
        }
        
        
        return oldWays[findIndex(3,range)];//ways[findIndex(S,range)];
    }
    
    int findIndex(int index, int range) {
        
        if(index == 0) {
            
            return range;
        }
        
        if(index > 0) {
            
            return range + index;
        }
        
        if(index < 0) {
            
            return range - abs(index);
        }
        
        return 0;
    }
};