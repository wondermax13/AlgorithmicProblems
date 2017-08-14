class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        if(nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < nums.size() - 1; i++) {
        
             if(i == 0 || nums[i] != nums[i-1]) {
                int start = i + 1, end = nums.size() - 1;
        
                while(start < end) {
            
                    int sum = nums[start] + nums[end];
                    int target = -nums[i];
                
                    if(sum < target) {
                    
                        ++start;
                    }
                    else if(sum > target) {
                    
                        --end;
                    }
                    else {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[start]);
                        vec.push_back(nums[end]);
                
                        res.push_back(vec);
                        
                        while(start < end && nums[start] == vec[1]) {
                            ++start;
                        }
                    }
                }
             }
        }
        
        return res;
    }
    
    /*++start; --end;
            while(nums[start] == nums[start-1]) {
                
                ++start;
            }
            
            while(nums[end] == nums[end+1]) {
                
                --end;
            }*/
            
                    /*map<int, int> s;
        
        for(auto num : nums) {
            
            s[num]++;
        }*/
};