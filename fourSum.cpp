class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        
        int size = nums.size();
        
        if(size >= 4) {
            
            sort(nums.begin(), nums.end());
            
            int index = 0;
            bool passedTarget = false, passedTarget1 = false;
            
            
            while(index < size-3 && !passedTarget) {
                
                index = findFirstDiff(nums, index, size - 3);
                
                if(nums[index] + nums[index + 1] + nums[index + 2] + nums[index + 3] <= target) {
                    
                    int index1=index + 1;
                    
                    while(index1 < size - 2 && !passedTarget1) {
                        
                        index1 = findFirstDiff(nums, index1, size - 2);
                    
                        if(nums[index] + nums[index1] + nums[index1 + 1] + nums[index1 + 2] <= target) {
                            
                            int left = index1 + 1, right = size - 1;
                            
                            while(left < right) {
                                
                                int sum=nums[left]+nums[right]+nums[index]+nums[index1];
                                
                                if(sum<target) left++;
                                else if(sum>target) right--;
                                
                                else{
                                    res.push_back(vector<int>{nums[index],nums[index1],nums[left],nums[right]});
                                    
                                    while(nums[left]==nums[left-1]&&left<right) {
                                        
                                        left++;   
                                    }
                                    while(nums[right]==nums[right+1]&&left<right) {
                                        
                                        right--;   
                                    }
                                }
                            }
                        }
                        else {
                            
                            passedTarget1 = true;
                        }
                        
                        ++index1;
                    }
                }
                else {
                    
                    passedTarget = true;
                }
                
                ++index;
            }
        }
        
        return res;
    }
    
    int findFirstDiff(
        vector<int>& nums, int startIndex, int maxIndex) {

        int index = startIndex;
        bool foundDiff = false;
        
        while(index < maxIndex - 1 && !foundDiff) {
            
            foundDiff = nums[index] != nums[index + 1];
            
            ++index;
        }
        
        return index;
    }
};